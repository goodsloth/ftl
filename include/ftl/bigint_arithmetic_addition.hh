#ifndef FTL_BIGINT_ARITHMETIC_ADDITION_HH
#define FTL_BIGINT_ARITHMETIC_ADDITION_HH

#include <ftl/identity.hh>
#include <ftl/bigint_base.hh>

#include <algorithm>
#include <cstdint>

namespace ftl {
namespace impl {

template<typename T, std::size_t A_BITS, std::size_t B_BITS>
struct required_bits_addition : identity<std::size_t, std::max(A_BITS, B_BITS) + 1> {};

}//namespace impl

/*
 * add
 */
template<typename T, size_t A_BITS, size_t B_BITS>
constexpr auto add(bigint<A_BITS, T> a, bigint<B_BITS, T> b) {
    constexpr size_t BITS = impl::required_bits_addition<T, A_BITS, B_BITS>::value;
    std::array<T, impl::required_elements<T, BITS>::value> result = {};
    T carry = { zero<T>::value };
    for (size_t i = 0; i < result.size() - 1; i++) {
        T ai = i < a.count ? a[i] : zero<T>::value;
        T bi = i < b.count ? b[i] : zero<T>::value;
        T current = ai + bi;
        T partial = current + carry;
        carry = (current < ai) || (partial < current) ? one<T>::value : zero<T>::value;
        result[i] = partial;
    }
    result[result.size() - 1] = carry;
    return bigint<BITS, T>{ result };
}

/*
 * add_in_place
 */
template<typename T, size_t A_BITS, size_t B_BITS>
constexpr auto add_in_place(bigint<A_BITS, T> a, bigint<B_BITS, T> b) {
    constexpr size_t BITS = std::max(A_BITS, B_BITS);
    std::array<T, impl::required_elements<T, BITS>::value> result = {};
    T carry = {zero<T>::value };
    for (size_t i = 0; i < result.count; i++) {
        T ai = i < a.count ? a[i] : zero<T>::value;
        T bi = i < b.count ? b[i] : zero<T>::value;
        T current = ai + bi;
        T partial = current + carry;
        carry = (current < ai) || (partial < current) ? one<T>::value : zero<T>::value;
        result[i] = partial;
    }
    return bigint<BITS, T>{ result };
}

/*
 * '+' (Addition Operators)
 */
template<size_t BITS, typename T>
constexpr auto operator+(bigint<BITS, T> a, T b) {
    bigint<std::numeric_limits<T>::digits, T> bb = {b };
    return add(a, bb);
}

template<size_t BITS, typename T>
constexpr auto operator+(bigint<BITS, T> a, bigint<BITS, T> b) {
    return add(a, b);
}

/*
 * ++ (Increment Operator)
 */
// TODO

}//namespace ftl

/*
 * add
 */
static_assert(ftl::add<std::uint8_t, 8, 8>({1}, {1})[0] == 2);
static_assert(ftl::add<std::uint8_t, 8, 8>({1}, {1})[1] == 0);
static_assert(ftl::add<std::uint8_t, 8, 8>({1}, {1}).size() == 2);
static_assert(ftl::add<std::uint8_t, 8, 8>({128}, {128})[0] == 0);
static_assert(ftl::add<std::uint8_t, 8, 8>({128}, {128})[1] == 1);
static_assert(ftl::add<std::uint8_t, 8, 8>({128}, {128}).size() == 2);
static_assert(ftl::add<std::uint8_t, 8, 8>({1}, {1})[0] == 2);
static_assert(ftl::add<std::uint8_t, 8, 16>({1}, {1})[1] == 0);
static_assert(ftl::add<std::uint8_t, 8, 16>({1}, {1})[2] == 0);
static_assert(ftl::add<std::uint8_t, 8, 16>({1}, {1}).size() == 3);
static_assert(ftl::add<std::uint8_t, 8, 16>({255}, {0, 255})[0] == 255);
static_assert(ftl::add<std::uint8_t, 8, 16>({255}, {0, 255})[1] == 255);
static_assert(ftl::add<std::uint8_t, 8, 16>({255}, {0, 255})[2] == 0);
static_assert(ftl::add<std::uint8_t, 8, 16>({1}, {1}).size() == 3);
static_assert(ftl::add<std::uint8_t, 8, 16>({255}, {0, 255}).highest_bit() == 16);

#endif//FTL_BIGINT_ARITHMETIC_ADDITION_HH