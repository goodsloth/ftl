#ifndef FTL_BIGINT_ARITHMETIC_SUBTRACTION_HH
#define FTL_BIGINT_ARITHMETIC_SUBTRACTION_HH

#include <ftl/identity.hh>
#include <ftl/bigint_base.hh>

#include <algorithm>
#include <cstdint>

namespace ftl {
namespace impl {

template<typename T, std::size_t A_BITS, std::size_t B_BITS>
struct required_bits_subtraction : identity<std::size_t, std::max(A_BITS, B_BITS) + 1> {};

} //namespace impl

/*
 * subtract
 */
template<typename T, std::size_t A_BITS, std::size_t B_BITS>
constexpr auto subtract(bigint<A_BITS, T> a, bigint<B_BITS, T> b) {
    bigint<impl::required_bits_subtraction<T, A_BITS, B_BITS>::value, T> result = { zero<T>::value };
    T carry = {zero<T>::value };
    for (std::size_t i = 0; i < result.count - 1; i++) {
        T ai = i < a.count ? a[i] : zero<T>::value;
        T bi = i < b.count ? b[i] : zero<T>::value;
        auto current = ai - bi;
        auto partial = current - carry;
        carry = (current > ai) || (partial > current) ? one<T>::value : zero<T>::value;
        result[i] = partial;
    }
    result[result.count - 1] = carry * static_cast<T>(-1);
    return result;
}

template<typename T, std::size_t A_BITS, std::size_t B_BITS>
constexpr auto subtract_in_place(bigint<A_BITS, T> a, bigint<B_BITS, T> b) {
    bigint<std::max(A_BITS, B_BITS), T> result = { zero<T>::value };
    T carry = {zero<T>::value };
    for (std::size_t i = 0; i < result.count; i++) {
        T ai = i < a.count ? a[i] : zero<T>::value;
        T bi = i < b.count ? b[i] : zero<T>::value;
        auto current = ai - bi;
        auto partial = current - carry;
        carry = (current > ai) || (partial > current) ? one<T>::value : zero<T>::value;
        result[i] = partial;
    }
    return result;
}

} //namespace ftl

#endif//FTL_BIGINT_ARITHMETIC_SUBTRACTION_HH