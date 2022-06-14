#ifndef FTL_BIGINT_BASE_HH
#define FTL_BIGINT_BASE_HH

#include <ftl/arithmetic.hh>
#include <ftl/identity.hh>

#include <array>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace ftl {
namespace impl {

template<typename T>
struct bigint_datatype {
    typedef void overflow_type;
};

template<>
struct bigint_datatype<std::uint8_t> {
    typedef std::uint16_t overflow_type;
};

template<>
struct bigint_datatype<std::uint16_t> {
    typedef std::uint32_t overflow_type;
};

template<>
struct bigint_datatype<std::uint32_t> {
    typedef std::uint64_t overflow_type;
};

template<typename T, std::size_t BITS>
struct required_elements : identity<
    std::size_t,
    (BITS / std::numeric_limits<T>::digits) + (BITS % std::numeric_limits<T>::digits == 0 ? 0 : 1)
> {};

template<typename T>
struct default_bits : identity<T, 256> {};

} //namespace impl

/*
 * bigint
 */
template<
    std::size_t BITS = impl::default_bits<std::size_t>::value,
    typename T = std::uint32_t,
    typename = std::enable_if_t<
        std::is_integral<T>::value
        && !std::is_signed<T>::value
        && (BITS > 0)
    >
>
struct bigint :
    std::array<T, impl::required_elements<T, BITS>::value>
{
    const size_t bits = BITS;
    const size_t count = impl::required_elements<T, BITS>::value;

    constexpr size_t highest_bit() const {
        size_t i = count - 1;
        while (i > 0 && this->at(i) == 0) {
            i--;
        }

        size_t j = std::numeric_limits<T>::digits;
        while (j > 0 && (this->at(i) & (0x01 << (j - 1))) == 0) {
            j--;
        }
        return i * std::numeric_limits<T>::digits + j;
    }
};

/*
 * zero
 */
template<size_t BITS, typename V>
struct zero<bigint<BITS, V>> {
    static constexpr auto value = bigint<BITS, V>{ zero<V>::value };
};

/*
 * one
 */
template<size_t BITS, typename V>
struct one<bigint<BITS, V>> {
    static constexpr auto value = bigint<BITS, V>{ one<V>::value };
};

/*
 * two
 */
template<size_t BITS, typename V>
struct two<bigint<BITS, V>> {
    static constexpr auto value = bigint<BITS, V>{ two<V>::value };
};

/*
 * three
 */
template<size_t BITS, typename V>
struct three<bigint<BITS, V>> {
    static constexpr auto value = bigint<BITS, V>{ three<V>::value };
};

/*
 * ten
 */
template<size_t BITS, typename V>
struct ten<bigint<BITS, V>> {
    static constexpr auto value = bigint<BITS, V>{ ten<V>::value };
};

/*
 * '==' (Equality Operator)
 */
template<typename T, size_t A_BITS, size_t B_BITS>
constexpr bool operator==(bigint<A_BITS, T> a, bigint<B_BITS, T> b) {
    constexpr auto count = std::max(a.count, b.count);
    for (size_t i = 0; i < count; ++i) {
        T ai = i < a.count ? a[i] : zero<T>::value;
        T bi = i < b.count ? b[i] : zero<T>::value;
        if (is_not_equal(a[i], b[i])) {
            return false;
        }
    }
    return true;
}

template<size_t BITS, typename T>
constexpr bool operator==(bigint<BITS, T> a, T b) {
    if (is_not_equal<T>(a[0], b)) {
        return false;
    }
    for (size_t i = 1; i < a.count; ++i) {
        if (is_not_equal(a[i], zero<T>::value)) {
            return false;
        }
    }
    return true;
}

} //namespace ftl

/*
 * bigint
 */

static_assert(ftl::bigint<16, std::uint8_t>({ 0 }).bits == 16);
static_assert(ftl::bigint<32, std::uint8_t>({ 0 }).bits == 32);
static_assert(ftl::bigint<64, std::uint8_t>({ 0 }).highest_bit() == 0);
static_assert(ftl::bigint<64, std::uint8_t>({ 1 }).highest_bit() == 1);
static_assert(ftl::bigint<64, std::uint8_t>({ 9 }).highest_bit() == 4);
static_assert(ftl::bigint<64, std::uint8_t>({ 255 }).highest_bit() == 8);
static_assert(ftl::bigint<64, std::uint8_t>({ 255, 127 }).highest_bit() == 15);
static_assert(ftl::bigint<64, std::uint8_t>({ 255, 255, 255, 1 }).highest_bit() == 25);
static_assert(ftl::bigint<64, std::uint8_t>({ 255, 255, 255, 255, 255, 255, 255, 63 }).highest_bit() == 62);
static_assert(ftl::bigint<8, std::uint8_t>({})[0] == static_cast<std::uint8_t>(0));
static_assert(ftl::bigint<8, std::uint8_t>({}).size() == 1);
static_assert(ftl::bigint<32, std::uint8_t>({}).size() == 4);
static_assert(ftl::bigint<64, std::uint8_t>({}).size() == 8);

/*
 * zero
 */
static_assert(ftl::zero<ftl::bigint<64, std::uint8_t>>::value.bits == 64);
static_assert(ftl::zero<ftl::bigint<64, std::uint8_t>>::value.count == 8);
static_assert(ftl::zero<ftl::bigint<64, std::uint8_t>>::value.highest_bit() == 0);

/*
 * one
 */
static_assert(ftl::one<ftl::bigint<64, std::uint8_t>>::value.bits == 64);
static_assert(ftl::one<ftl::bigint<64, std::uint8_t>>::value.count == 8);
static_assert(ftl::one<ftl::bigint<64, std::uint8_t>>::value.highest_bit() == 1);

/*
 * two
 */
static_assert(ftl::two<ftl::bigint<64, std::uint8_t>>::value.bits == 64);
static_assert(ftl::two<ftl::bigint<64, std::uint8_t>>::value.count == 8);
static_assert(ftl::two<ftl::bigint<64, std::uint8_t>>::value.highest_bit() == 2);

/*
 * three
 */
static_assert(ftl::three<ftl::bigint<64, std::uint8_t>>::value.bits == 64);
static_assert(ftl::three<ftl::bigint<64, std::uint8_t>>::value.count == 8);
static_assert(ftl::three<ftl::bigint<64, std::uint8_t>>::value.highest_bit() == 2);

/*
 * ten
 */
static_assert(ftl::ten<ftl::bigint<64, std::uint8_t>>::value.bits == 64);
static_assert(ftl::ten<ftl::bigint<64, std::uint8_t>>::value.count == 8);
static_assert(ftl::ten<ftl::bigint<64, std::uint8_t>>::value.highest_bit() == 4);

#endif//FTL_BIGINT_BASE_HH