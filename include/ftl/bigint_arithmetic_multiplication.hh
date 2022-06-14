#ifndef FTL_BIGINT_ARITHMETIC_MULTIPLICATION_HH
#define FTL_BIGINT_ARITHMETIC_MULTIPLICATION_HH

#include <ftl/identity.hh>
#include <ftl/bigint_base.hh>

#include <algorithm>
#include <cstdint>

namespace ftl {
namespace impl {

template<typename T, std::size_t A_BITS, std::size_t B_BITS>
struct required_bits_multiplication : identity<size_t, A_BITS + B_BITS> {};

} //namespace impl

/*
 * multiply
 */
template<typename T, std::size_t A_BITS, std::size_t B_BITS>
constexpr auto multiply(bigint<A_BITS, T> a, bigint<B_BITS, T> b) {
    using OverflowType = typename impl::bigint_datatype<T>::overflow_type;
    bigint<impl::required_bits_multiplication<T, A_BITS, B_BITS>::value, T> result = { zero<T>::value };
    for (auto bi = 0; bi < b.count; ++bi) {
        T k = 0;
        const auto count = std::min(a.count, result.count - bi);
        for (auto ai = 0; ai < count; ++ai) {
            OverflowType product = multiply(
            static_cast<OverflowType>(a[ai]),
            static_cast<OverflowType>(b[bi]));
            OverflowType partial = add(
            static_cast<OverflowType>(result[ai + bi]),
            static_cast<OverflowType>(k));
            OverflowType sum = add(partial, product);
            result[ai + bi] = static_cast<T>(sum);
            k = sum >> static_cast<T>(std::numeric_limits<T>::digits);
        }
        if (bi + count < result.count) {
            result[bi + count] = k;
        }
    }
    return result;
}

/*
 * '*' (Multiplication Operators)
 */
template<std::size_t BITS, typename T>
constexpr auto operator*(bigint<BITS, T> a, T b) {
    bigint<std::numeric_limits<T>::digits, T> bb = {b };
    return multiply(a, bb);
}

template<typename T, std::size_t A_BITS, std::size_t B_BITS>
constexpr auto operator*(bigint<A_BITS, T> a, bigint<B_BITS, T> b) {
    return multiply(a, b);
}

} //namespace ftl

static_assert(0 + (64 << 8LL) == 128 * 128);
static_assert(ftl::multiply<std::uint8_t, 8, 8>({128}, {128})[0] == 0);
static_assert(ftl::multiply<std::uint8_t, 8, 8>({128}, {128})[1] == 64);
static_assert(ftl::multiply<std::uint8_t, 8, 8>({128}, {128}).size() == 2);
static_assert(123 + (238 << 8) == 61051);
static_assert(141 + (25 << 8) + (1 << 16) == 72077);
static_assert(191LL + (92LL << 8LL) + (72LL << 16LL) + (6LL << 24LL) + (1LL << 32LL) == 61051LL * 72077LL);
static_assert(ftl::multiply<std::uint8_t, 16, 24>({123, 238}, {141, 25, 1})[0] == 191);
static_assert(ftl::multiply<std::uint8_t, 16, 24>({123, 238}, {141, 25, 1})[1] == 92);
static_assert(ftl::multiply<std::uint8_t, 16, 24>({123, 238}, {141, 25, 1})[2] == 72);
static_assert(ftl::multiply<std::uint8_t, 16, 24>({123, 238}, {141, 25, 1})[3] == 6);
static_assert(ftl::multiply<std::uint8_t, 16, 24>({123, 238}, {141, 25, 1})[4] == 1);
static_assert(ftl::multiply<std::uint8_t, 16, 24>({123, 238}, {141, 25, 1}).size() == 5);

#endif//FTL_BIGINT_ARITHMETIC_MULTIPLICATION_HH