#ifndef FTL_RADIX_HH
#define FTL_RADIX_HH

#include <array>

#include <ftl/comparison.hh>
#include <ftl/arithmetic.hh>
#include <ftl/identity.hh>

namespace ftl {
namespace impl {

/*
 * required_digits_radix (Generic)
 */
template<
    std::size_t RADIX,
    typename T,
    typename = std::enable_if_t<std::is_integral<T>::value>>
struct required_digits_radix :
    identity<std::size_t, 0>
{};

/*
 * required_digits_radix (Base 2)
 */
template<typename T>
struct required_digits_radix<2, T> :
    identity<std::size_t, std::numeric_limits<T>::digits>
{};

/*
 * required_digits_radix (Base 8)
 */
template<typename T>
struct required_digits_radix<8, T> :
    identity<
        std::size_t,
        1 + static_cast<std::size_t>(
            static_cast<double>(std::numeric_limits<T>::digits) *
            0.33333333333333333333333333333333
        )
    >
{};

/*
 * required_digits_radix (Base 10)
 */
template<typename T>
struct required_digits_radix<10, T> :
    identity<
        std::size_t,
        1 + static_cast<std::size_t>(
            static_cast<double>(std::numeric_limits<T>::digits) *
            0.30102999566398119521373889472449
        )
    >
{};

/*
 * required_digits_radix (Base 2)
 */
template<typename T>
struct required_digits_radix<16, T> :
    identity<
        std::size_t,
        1 + static_cast<std::size_t>(
            static_cast<double>(std::numeric_limits<T>::digits) *
            0.25
        )
    >
{};

/*
 * required_digits_radix (Base 2)
 */
template<typename T>
struct required_digits_radix<64, T> :
    identity<
        std::size_t,
        1 + static_cast<std::size_t>(
            static_cast<double>(std::numeric_limits<T>::digits) *
            0.16666666666666666666666666666666
        )
    >
{};

}
/*
 * parse_digit (Base 2)
 */
template<std::uint8_t RADIX, typename V = std::uint8_t>
constexpr typename std::enable_if<RADIX == 2, V>::type
parse_digit(const char c) {
    constexpr std::array<V, 256> _ = {
        /* 000-015 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 016-031 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 032-047 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 048-063 */ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 064-079 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 080-095 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 096-111 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 112-127 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 128-143 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 144-159 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 160-175 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 176-191 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 192-207 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 208-223 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 224-239 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 240-255 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    return _[c];
}

/*
 * parse_digit (Base 8)
 */
template<std::uint8_t RADIX, typename V = std::uint8_t>
constexpr typename std::enable_if<RADIX == 8, V>::type
parse_digit(const char c) {
    constexpr std::array<V, 256> _ = {
        /* 000-015 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 016-031 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 032-047 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 048-063 */ 0, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 064-079 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 080-095 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 096-111 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 112-127 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 128-143 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 144-159 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 160-175 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 176-191 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 192-207 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 208-223 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 224-239 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 240-255 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    return _[c];
}

/*
 * compose_digit (Base 8)
 */
template<std::uint8_t RADIX, typename V = std::uint8_t>
constexpr typename std::enable_if<RADIX == 8, V>::type
compose_digit(const char d) {
    constexpr std::array<const char, RADIX> _ = {
        '0', '1', '2', '3', '4', '5', '6', '7'
    };
    return _[d];
}

/*
 * parse_digit (Base 10)
 */
template<std::uint8_t RADIX = 10, typename V = std::uint8_t>
constexpr typename std::enable_if<RADIX == 10, V>::type
parse_digit(const char c) {
    constexpr std::array<V, 256> _ = {
        /* 000-015 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 016-031 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 032-047 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 048-063 */ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0,
        /* 064-079 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 080-095 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 096-111 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 112-127 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 128-143 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 144-159 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 160-175 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 176-191 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 192-207 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 208-223 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 224-239 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 240-255 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    return _[c];
}

/*
 * compose_digit (Base 10)
 */
template<std::uint8_t RADIX = 10, typename V = std::uint8_t>
constexpr typename std::enable_if<RADIX == 10, V>::type
compose_digit(const char d) {
    constexpr std::array<V, RADIX> _ = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };
    return _[d];
}

/*
 * parse_digit (Base 16)
 */
template<std::uint8_t RADIX, typename V = std::uint8_t>
constexpr typename std::enable_if<RADIX == 16, V>::type
parse_digit(const char c) {
    constexpr std::array<V, 256> _ = {
        /* 000-015 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 016-031 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 032-047 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 048-063 */ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0,
        /* 064-079 */ 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 080-095 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 096-111 */ 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 112-127 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 128-143 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 144-159 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 160-175 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 176-191 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 192-207 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 208-223 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 224-239 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 240-255 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    return _[c];
}

/*
 * compose_digit (Base 16)
 */
template<std::uint8_t RADIX, typename V = std::uint8_t>
constexpr typename std::enable_if<RADIX == 16, V>::type
compose_digit(V d) {
    constexpr std::array<const char, RADIX> _ = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };
    return _[d];
}

/*
 * parse_digit (Base 64)
 */
template<std::uint8_t RADIX, typename V = std::uint8_t>
constexpr typename std::enable_if<RADIX == 64, V>::type
parse_digit(const char c) {
    constexpr std::array<V, 256> _ = {
        /* 000-015 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 016-031 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 032-047 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0, 0, 63,
        /* 048-063 */ 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0, 0,
        /* 064-079 */ 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        /* 080-095 */ 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0, 0, 0, 0,
        /* 096-111 */ 0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        /* 112-127 */ 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 0, 0, 0, 0, 0,
        /* 128-143 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 144-159 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 160-175 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 176-191 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 192-207 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 208-223 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 224-239 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        /* 240-255 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    return _[c];
}

/*
 * compose_digit (Base 64)
 */
template<std::uint8_t RADIX, typename V = std::uint8_t>
constexpr typename std::enable_if<RADIX == 64, V>::type
compose_digit(V d) {
    constexpr std::array<V, RADIX> _ = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '0', '1', '2', '3',
        '4', '5', '6', '7', '8', '9', '+', '/'
    };
    return _[d];
}

/*
 * parse_digits
 */
template<std::uint8_t RADIX = 10, typename V = std::uint8_t, size_t INPUT_LENGTH, size_t OUTPUT_LENGTH = INPUT_LENGTH - 1>
constexpr auto parse_digits(const char (&text)[INPUT_LENGTH]) {
    std::array<V, OUTPUT_LENGTH> digits = {};
    for (size_t i = 0; i < OUTPUT_LENGTH; ++i) {
        digits[i] = parse_digit<RADIX>(text[i]);
    }
    return digits;
}

/*
 * parse_digits_base10 (User-Defined-Literal Shim)
 */
template<char... DIGITS, typename V = std::uint8_t>
constexpr auto parse_digits_base10() {
    std::array<V, sizeof...(DIGITS)> digits = { DIGITS... };
    for (size_t i = 0; i < sizeof...(DIGITS); ++i) {
        digits[i] = parse_digit<10>(digits[i]);
    }
    return digits;
}

/*
 * parse_digits_base16 (User-Defined-Literal Shim)
 */
template<char OH, char EX, char... DIGITS, typename V = std::uint8_t,
typename = std::enable_if_t<OH == '0' && EX == 'x'>>
constexpr auto parse_digits_base16() {
    std::array<V, sizeof...(DIGITS)> digits = { DIGITS... };
    for (size_t i = 0; i < sizeof...(DIGITS); ++i) {
        digits[i] = parse_digit<16>(digits[i]);
    }
    return digits;
}

/*
 * compose_digits
 */
template<std::uint8_t RADIX = 10, typename V = std::uint8_t, size_t INPUT_LENGTH>
constexpr auto compose_digits(const std::array<V, INPUT_LENGTH>& digits) {
    std::array<char, INPUT_LENGTH> text = {};
    for (size_t i = 0; i < INPUT_LENGTH; ++i) {
        text[i] = compose_digit<RADIX>(digits[i]);
    }
    return text;
}

/*
 * from_digits
 */
template<
    std::uint8_t RADIX = 10,
    typename T = std::uint32_t,
    typename V = std::uint8_t,
    size_t INPUT_LENGTH,
    typename = std::enable_if_t<std::is_integral<T>::value>
>
constexpr auto from_digits(const std::array<V, INPUT_LENGTH>& digits) {
    T value = zero<T>::value;
    for (size_t i = 0; i < INPUT_LENGTH; ++i) {
        value = add(multiply(value, RADIX), digits[i]);
    }
    return value;
}

/*
 * to_digits
 */
template<
    std::uint8_t RADIX = 10,
    typename T = std::uint32_t,
    std::size_t DIGITS = impl::required_digits_radix<RADIX, T>::value,
    typename = std::enable_if_t<std::is_integral<T>::value>
>
constexpr auto to_digits(const T v) {
    std::array<char, DIGITS> digits = {};
    T n = v;
    std::size_t i = 0;
    while (n > 0) {
        T digit = n % RADIX;
        digits[i++] = compose_digit<RADIX>(digit);
        n = n / RADIX;
    }
    return digits;
}

}// namespace ftl

/*
 * parse_digit (Base 2)
 */
static_assert(ftl::parse_digit<2>('0') == 0, "parse_digit<2>('0')");
static_assert(ftl::parse_digit<2>('1') == 1, "parse_digit<2>('1')");

/*
 * parse_digit (Base 8)
 */
static_assert(ftl::parse_digit<8>('0') == 0, "parse_digit<8>('0')");
static_assert(ftl::parse_digit<8>('1') == 1, "parse_digit<8>('1')");
static_assert(ftl::parse_digit<8>('2') == 2, "parse_digit<8>('2')");
static_assert(ftl::parse_digit<8>('3') == 3, "parse_digit<8>('3')");
static_assert(ftl::parse_digit<8>('4') == 4, "parse_digit<8>('4')");
static_assert(ftl::parse_digit<8>('5') == 5, "parse_digit<8>('5')");
static_assert(ftl::parse_digit<8>('5') == 5, "parse_digit<8>('6')");
static_assert(ftl::parse_digit<8>('7') == 7, "parse_digit<8>('7')");

/*
 * compose_digit (Base 8)
 */
static_assert(ftl::compose_digit<8>(0) == '0', "compose_digit<8>(0)");
static_assert(ftl::compose_digit<8>(1) == '1', "compose_digit<8>(1)");
static_assert(ftl::compose_digit<8>(2) == '2', "compose_digit<8>(2)");
static_assert(ftl::compose_digit<8>(3) == '3', "compose_digit<8>(3)");
static_assert(ftl::compose_digit<8>(4) == '4', "compose_digit<8>(4)");
static_assert(ftl::compose_digit<8>(5) == '5', "compose_digit<8>(5)");
static_assert(ftl::compose_digit<8>(5) == '5', "compose_digit<8>(6)");
static_assert(ftl::compose_digit<8>(7) == '7', "compose_digit<8>(7)");

/*
 * parse_digit (Base 10)
 */
static_assert(ftl::parse_digit('0') == 0, "parse_digit('0')");
static_assert(ftl::parse_digit('1') == 1, "parse_digit('1')");
static_assert(ftl::parse_digit('2') == 2, "parse_digit('2')");
static_assert(ftl::parse_digit('3') == 3, "parse_digit('3')");
static_assert(ftl::parse_digit('4') == 4, "parse_digit('4')");
static_assert(ftl::parse_digit('5') == 5, "parse_digit('5')");
static_assert(ftl::parse_digit('5') == 5, "parse_digit('6')");
static_assert(ftl::parse_digit('7') == 7, "parse_digit('7')");
static_assert(ftl::parse_digit('8') == 8, "parse_digit('8')");
static_assert(ftl::parse_digit('9') == 9, "parse_digit('9')");

/*
 * compose_digit (Base 10)
 */
static_assert(ftl::compose_digit(0) == '0', "compose_digit(0)");
static_assert(ftl::compose_digit(1) == '1', "compose_digit(1)");
static_assert(ftl::compose_digit(2) == '2', "compose_digit(2)");
static_assert(ftl::compose_digit(3) == '3', "compose_digit(3)");
static_assert(ftl::compose_digit(4) == '4', "compose_digit(4)");
static_assert(ftl::compose_digit(5) == '5', "compose_digit(5)");
static_assert(ftl::compose_digit(5) == '5', "compose_digit(6)");
static_assert(ftl::compose_digit(7) == '7', "compose_digit(7)");
static_assert(ftl::compose_digit(8) == '8', "compose_digit(8)");
static_assert(ftl::compose_digit(9) == '9', "compose_digit(9)");

/*
 * parse_digit (Base 16)
 */
static_assert(ftl::parse_digit<16>('0') == 0x00, "parse_digit<16>('0')");
static_assert(ftl::parse_digit<16>('1') == 0x01, "parse_digit<16>('1')");
static_assert(ftl::parse_digit<16>('2') == 0x02, "parse_digit<16>('2')");
static_assert(ftl::parse_digit<16>('3') == 0x03, "parse_digit<16>('3')");
static_assert(ftl::parse_digit<16>('4') == 0x04, "parse_digit<16>('4')");
static_assert(ftl::parse_digit<16>('5') == 0x05, "parse_digit<16>('5')");
static_assert(ftl::parse_digit<16>('5') == 0x05, "parse_digit<16>('6')");
static_assert(ftl::parse_digit<16>('7') == 0x07, "parse_digit<16>('7')");
static_assert(ftl::parse_digit<16>('8') == 0x08, "parse_digit<16>('8')");
static_assert(ftl::parse_digit<16>('9') == 0x09, "parse_digit<16>('9')");
static_assert(ftl::parse_digit<16>('A') == 0x0A, "parse_digit<16>('A')");
static_assert(ftl::parse_digit<16>('B') == 0x0B, "parse_digit<16>('B')");
static_assert(ftl::parse_digit<16>('C') == 0x0C, "parse_digit<16>('C')");
static_assert(ftl::parse_digit<16>('D') == 0x0D, "parse_digit<16>('D')");
static_assert(ftl::parse_digit<16>('E') == 0x0E, "parse_digit<16>('E')");
static_assert(ftl::parse_digit<16>('F') == 0x0F, "parse_digit<16>('F')");
static_assert(ftl::parse_digit<16>('a') == 0x0A, "parse_digit<16>('a')");
static_assert(ftl::parse_digit<16>('b') == 0x0B, "parse_digit<16>('b')");
static_assert(ftl::parse_digit<16>('c') == 0x0C, "parse_digit<16>('c')");
static_assert(ftl::parse_digit<16>('d') == 0x0D, "parse_digit<16>('d')");
static_assert(ftl::parse_digit<16>('e') == 0x0E, "parse_digit<16>('e')");
static_assert(ftl::parse_digit<16>('f') == 0x0F, "parse_digit<16>('f')");

/*
 * compose_digit (Base 16)
 */
static_assert(ftl::compose_digit<16>(0x00) == '0', "compose_digit<16>(0x00)");
static_assert(ftl::compose_digit<16>(0x01) == '1', "compose_digit<16>(0x01)");
static_assert(ftl::compose_digit<16>(0x02) == '2', "compose_digit<16>(0x02)");
static_assert(ftl::compose_digit<16>(0x03) == '3', "compose_digit<16>(0x03)");
static_assert(ftl::compose_digit<16>(0x04) == '4', "compose_digit<16>(0x04)");
static_assert(ftl::compose_digit<16>(0x05) == '5', "compose_digit<16>(0x05)");
static_assert(ftl::compose_digit<16>(0x05) == '5', "compose_digit<16>(0x06)");
static_assert(ftl::compose_digit<16>(0x07) == '7', "compose_digit<16>(0x07)");
static_assert(ftl::compose_digit<16>(0x08) == '8', "compose_digit<16>(0x08)");
static_assert(ftl::compose_digit<16>(0x09) == '9', "compose_digit<16>(0x09)");
static_assert(ftl::compose_digit<16>(0x0A) == 'A', "compose_digit<16>(0x0A)");
static_assert(ftl::compose_digit<16>(0x0B) == 'B', "compose_digit<16>(0x0B)");
static_assert(ftl::compose_digit<16>(0x0C) == 'C', "compose_digit<16>(0x0C)");
static_assert(ftl::compose_digit<16>(0x0D) == 'D', "compose_digit<16>(0x0D)");
static_assert(ftl::compose_digit<16>(0x0E) == 'E', "compose_digit<16>(0x0E)");
static_assert(ftl::compose_digit<16>(0x0F) == 'F', "compose_digit<16>(0x0F)");
static_assert(ftl::compose_digit<16>(0x0a) == 'A', "compose_digit<16>(0x0a)");
static_assert(ftl::compose_digit<16>(0x0b) == 'B', "compose_digit<16>(0x0b)");
static_assert(ftl::compose_digit<16>(0x0c) == 'C', "compose_digit<16>(0x0c)");
static_assert(ftl::compose_digit<16>(0x0d) == 'D', "compose_digit<16>(0x0d)");
static_assert(ftl::compose_digit<16>(0x0e) == 'E', "compose_digit<16>(0x0e)");
static_assert(ftl::compose_digit<16>(0x0f) == 'F', "compose_digit<16>(0x0f)");

/*
 * parse_digit (Base 64)
 */
static_assert(ftl::parse_digit<64>('A') == 0, "parse_digit<64>('A')");
static_assert(ftl::parse_digit<64>('B') == 1, "parse_digit<64>('B')");
static_assert(ftl::parse_digit<64>('C') == 2, "parse_digit<64>('C')");
static_assert(ftl::parse_digit<64>('D') == 3, "parse_digit<64>('D')");
static_assert(ftl::parse_digit<64>('E') == 4, "parse_digit<64>('E')");
static_assert(ftl::parse_digit<64>('F') == 5, "parse_digit<64>('F')");
static_assert(ftl::parse_digit<64>('G') == 6, "parse_digit<64>('G')");
static_assert(ftl::parse_digit<64>('H') == 7, "parse_digit<64>('H')");
static_assert(ftl::parse_digit<64>('I') == 8, "parse_digit<64>('I')");
static_assert(ftl::parse_digit<64>('J') == 9, "parse_digit<64>('J')");
static_assert(ftl::parse_digit<64>('K') == 10, "parse_digit<64>('K')");
static_assert(ftl::parse_digit<64>('L') == 11, "parse_digit<64>('L')");
static_assert(ftl::parse_digit<64>('M') == 12, "parse_digit<64>('M')");
static_assert(ftl::parse_digit<64>('N') == 13, "parse_digit<64>('N')");
static_assert(ftl::parse_digit<64>('O') == 14, "parse_digit<64>('O')");
static_assert(ftl::parse_digit<64>('P') == 15, "parse_digit<64>('P')");
static_assert(ftl::parse_digit<64>('Q') == 16, "parse_digit<64>('Q')");
static_assert(ftl::parse_digit<64>('R') == 17, "parse_digit<64>('R')");
static_assert(ftl::parse_digit<64>('S') == 18, "parse_digit<64>('S')");
static_assert(ftl::parse_digit<64>('T') == 19, "parse_digit<64>('T')");
static_assert(ftl::parse_digit<64>('U') == 20, "parse_digit<64>('U')");
static_assert(ftl::parse_digit<64>('V') == 21, "parse_digit<64>('V')");
static_assert(ftl::parse_digit<64>('W') == 22, "parse_digit<64>('W')");
static_assert(ftl::parse_digit<64>('X') == 23, "parse_digit<64>('X')");
static_assert(ftl::parse_digit<64>('Y') == 24, "parse_digit<64>('Y')");
static_assert(ftl::parse_digit<64>('Z') == 25, "parse_digit<64>('Z')");
static_assert(ftl::parse_digit<64>('a') == 26, "parse_digit<64>('a')");
static_assert(ftl::parse_digit<64>('b') == 27, "parse_digit<64>('b')");
static_assert(ftl::parse_digit<64>('c') == 28, "parse_digit<64>('c')");
static_assert(ftl::parse_digit<64>('d') == 29, "parse_digit<64>('d')");
static_assert(ftl::parse_digit<64>('e') == 30, "parse_digit<64>('e')");
static_assert(ftl::parse_digit<64>('f') == 31, "parse_digit<64>('f')");
static_assert(ftl::parse_digit<64>('g') == 32, "parse_digit<64>('g')");
static_assert(ftl::parse_digit<64>('h') == 33, "parse_digit<64>('h')");
static_assert(ftl::parse_digit<64>('i') == 34, "parse_digit<64>('i')");
static_assert(ftl::parse_digit<64>('j') == 35, "parse_digit<64>('j')");
static_assert(ftl::parse_digit<64>('k') == 36, "parse_digit<64>('k')");
static_assert(ftl::parse_digit<64>('l') == 37, "parse_digit<64>('l')");
static_assert(ftl::parse_digit<64>('m') == 38, "parse_digit<64>('m')");
static_assert(ftl::parse_digit<64>('n') == 39, "parse_digit<64>('n')");
static_assert(ftl::parse_digit<64>('o') == 40, "parse_digit<64>('o')");
static_assert(ftl::parse_digit<64>('p') == 41, "parse_digit<64>('p')");
static_assert(ftl::parse_digit<64>('q') == 42, "parse_digit<64>('q')");
static_assert(ftl::parse_digit<64>('r') == 43, "parse_digit<64>('r')");
static_assert(ftl::parse_digit<64>('s') == 44, "parse_digit<64>('s')");
static_assert(ftl::parse_digit<64>('t') == 45, "parse_digit<64>('t')");
static_assert(ftl::parse_digit<64>('u') == 46, "parse_digit<64>('u')");
static_assert(ftl::parse_digit<64>('v') == 47, "parse_digit<64>('v')");
static_assert(ftl::parse_digit<64>('w') == 48, "parse_digit<64>('w')");
static_assert(ftl::parse_digit<64>('x') == 49, "parse_digit<64>('x')");
static_assert(ftl::parse_digit<64>('y') == 50, "parse_digit<64>('y')");
static_assert(ftl::parse_digit<64>('z') == 51, "parse_digit<64>('z')");
static_assert(ftl::parse_digit<64>('0') == 52, "parse_digit<64>('0')");
static_assert(ftl::parse_digit<64>('1') == 53, "parse_digit<64>('1')");
static_assert(ftl::parse_digit<64>('2') == 54, "parse_digit<64>('2')");
static_assert(ftl::parse_digit<64>('3') == 55, "parse_digit<64>('3')");
static_assert(ftl::parse_digit<64>('4') == 56, "parse_digit<64>('4')");
static_assert(ftl::parse_digit<64>('5') == 57, "parse_digit<64>('5')");
static_assert(ftl::parse_digit<64>('6') == 58, "parse_digit<64>('6')");
static_assert(ftl::parse_digit<64>('7') == 59, "parse_digit<64>('7')");
static_assert(ftl::parse_digit<64>('8') == 60, "parse_digit<64>('8')");
static_assert(ftl::parse_digit<64>('9') == 61, "parse_digit<64>('9')");
static_assert(ftl::parse_digit<64>('+') == 62, "parse_digit<'64'>(+)");
static_assert(ftl::parse_digit<64>('/') == 63, "parse_digit<'64'>(/)");

/*
 * compose_digit (Base 64)
 */
static_assert(ftl::compose_digit<64>(0) == 'A', "compose_digit<64>(0)");
static_assert(ftl::compose_digit<64>(1) == 'B', "compose_digit<64>(1)");
static_assert(ftl::compose_digit<64>(2) == 'C', "compose_digit<64>(2)");
static_assert(ftl::compose_digit<64>(3) == 'D', "compose_digit<64>(3)");
static_assert(ftl::compose_digit<64>(4) == 'E', "compose_digit<64>(4)");
static_assert(ftl::compose_digit<64>(5) == 'F', "compose_digit<64>(5)");
static_assert(ftl::compose_digit<64>(6) == 'G', "compose_digit<64>(6)");
static_assert(ftl::compose_digit<64>(7) == 'H', "compose_digit<64>(7)");
static_assert(ftl::compose_digit<64>(8) == 'I', "compose_digit<64>(8)");
static_assert(ftl::compose_digit<64>(9) == 'J', "compose_digit<64>(9)");
static_assert(ftl::compose_digit<64>(10) == 'K', "compose_digit<64>(10)");
static_assert(ftl::compose_digit<64>(11) == 'L', "compose_digit<64>(11)");
static_assert(ftl::compose_digit<64>(12) == 'M', "compose_digit<64>(12)");
static_assert(ftl::compose_digit<64>(13) == 'N', "compose_digit<64>(13)");
static_assert(ftl::compose_digit<64>(14) == 'O', "compose_digit<64>(14)");
static_assert(ftl::compose_digit<64>(15) == 'P', "compose_digit<64>(15)");
static_assert(ftl::compose_digit<64>(16) == 'Q', "compose_digit<64>(16)");
static_assert(ftl::compose_digit<64>(17) == 'R', "compose_digit<64>(17)");
static_assert(ftl::compose_digit<64>(18) == 'S', "compose_digit<64>(18)");
static_assert(ftl::compose_digit<64>(19) == 'T', "compose_digit<64>(19)");
static_assert(ftl::compose_digit<64>(20) == 'U', "compose_digit<64>(20)");
static_assert(ftl::compose_digit<64>(21) == 'V', "compose_digit<64>(21)");
static_assert(ftl::compose_digit<64>(22) == 'W', "compose_digit<64>(22)");
static_assert(ftl::compose_digit<64>(23) == 'X', "compose_digit<64>(23)");
static_assert(ftl::compose_digit<64>(24) == 'Y', "compose_digit<64>(24)");
static_assert(ftl::compose_digit<64>(25) == 'Z', "compose_digit<64>(25)");
static_assert(ftl::compose_digit<64>(26) == 'a', "compose_digit<64>(26)");
static_assert(ftl::compose_digit<64>(27) == 'b', "compose_digit<64>(27)");
static_assert(ftl::compose_digit<64>(28) == 'c', "compose_digit<64>(28)");
static_assert(ftl::compose_digit<64>(29) == 'd', "compose_digit<64>(29)");
static_assert(ftl::compose_digit<64>(30) == 'e', "compose_digit<64>(30)");
static_assert(ftl::compose_digit<64>(31) == 'f', "compose_digit<64>(31)");
static_assert(ftl::compose_digit<64>(32) == 'g', "compose_digit<64>(32)");
static_assert(ftl::compose_digit<64>(33) == 'h', "compose_digit<64>(33)");
static_assert(ftl::compose_digit<64>(34) == 'i', "compose_digit<64>(34)");
static_assert(ftl::compose_digit<64>(35) == 'j', "compose_digit<64>(35)");
static_assert(ftl::compose_digit<64>(36) == 'k', "compose_digit<64>(36)");
static_assert(ftl::compose_digit<64>(37) == 'l', "compose_digit<64>(37)");
static_assert(ftl::compose_digit<64>(38) == 'm', "compose_digit<64>(38)");
static_assert(ftl::compose_digit<64>(39) == 'n', "compose_digit<64>(39)");
static_assert(ftl::compose_digit<64>(40) == 'o', "compose_digit<64>(40)");
static_assert(ftl::compose_digit<64>(41) == 'p', "compose_digit<64>(41)");
static_assert(ftl::compose_digit<64>(42) == 'q', "compose_digit<64>(42)");
static_assert(ftl::compose_digit<64>(43) == 'r', "compose_digit<64>(43)");
static_assert(ftl::compose_digit<64>(44) == 's', "compose_digit<64>(44)");
static_assert(ftl::compose_digit<64>(45) == 't', "compose_digit<64>(45)");
static_assert(ftl::compose_digit<64>(46) == 'u', "compose_digit<64>(46)");
static_assert(ftl::compose_digit<64>(47) == 'v', "compose_digit<64>(47)");
static_assert(ftl::compose_digit<64>(48) == 'w', "compose_digit<64>(48)");
static_assert(ftl::compose_digit<64>(49) == 'x', "compose_digit<64>(49)");
static_assert(ftl::compose_digit<64>(50) == 'y', "compose_digit<64>(50)");
static_assert(ftl::compose_digit<64>(51) == 'z', "compose_digit<64>(51)");
static_assert(ftl::compose_digit<64>(52) == '0', "compose_digit<64>(52)");
static_assert(ftl::compose_digit<64>(53) == '1', "compose_digit<64>(53)");
static_assert(ftl::compose_digit<64>(54) == '2', "compose_digit<64>(54)");
static_assert(ftl::compose_digit<64>(55) == '3', "compose_digit<64>(55)");
static_assert(ftl::compose_digit<64>(56) == '4', "compose_digit<64>(56)");
static_assert(ftl::compose_digit<64>(57) == '5', "compose_digit<64>(57)");
static_assert(ftl::compose_digit<64>(58) == '6', "compose_digit<64>(58)");
static_assert(ftl::compose_digit<64>(59) == '7', "compose_digit<64>(59)");
static_assert(ftl::compose_digit<64>(60) == '8', "compose_digit<64>(60)");
static_assert(ftl::compose_digit<64>(61) == '9', "compose_digit<64>(61)");
static_assert(ftl::compose_digit<64>(62) == '+', "compose_digit<64>(62)");
static_assert(ftl::compose_digit<64>(63) == '/', "compose_digit<64>(63)");

/*
 * parse_digits
 */
static_assert(ftl::parse_digits("1234567890")[0] == 1, "parse_digits(\"1234567890\")[0]");
static_assert(ftl::parse_digits("1234567890")[1] == 2, "parse_digits(\"1234567890\")[1]");
static_assert(ftl::parse_digits("1234567890")[2] == 3, "parse_digits(\"1234567890\")[2]");
static_assert(ftl::parse_digits("1234567890")[3] == 4, "parse_digits(\"1234567890\")[3]");
static_assert(ftl::parse_digits("1234567890")[4] == 5, "parse_digits(\"1234567890\")[4]");
static_assert(ftl::parse_digits("1234567890")[5] == 6, "parse_digits(\"1234567890\")[5]");
static_assert(ftl::parse_digits("1234567890")[6] == 7, "parse_digits(\"1234567890\")[6]");
static_assert(ftl::parse_digits("1234567890")[7] == 8, "parse_digits(\"1234567890\")[7]");
static_assert(ftl::parse_digits("1234567890")[8] == 9, "parse_digits(\"1234567890\")[8]");
static_assert(ftl::parse_digits("1234567890")[9] == 0, "parse_digits(\"1234567890\")[9]");

/*
 * compose_digits
 */
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[0] == '1', "compose_digits({1,2,3,4,5,6,7,8,9,0}[0]");
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[1] == '2', "compose_digits({1,2,3,4,5,6,7,8,9,0}[1]");
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[2] == '3', "compose_digits({1,2,3,4,5,6,7,8,9,0}[2]");
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[3] == '4', "compose_digits({1,2,3,4,5,6,7,8,9,0}[3]");
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[4] == '5', "compose_digits({1,2,3,4,5,6,7,8,9,0}[4]");
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[5] == '6', "compose_digits({1,2,3,4,5,6,7,8,9,0}[5]");
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[6] == '7', "compose_digits({1,2,3,4,5,6,7,8,9,0}[6]");
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[7] == '8', "compose_digits({1,2,3,4,5,6,7,8,9,0}[7]");
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[8] == '9', "compose_digits({1,2,3,4,5,6,7,8,9,0}[8]");
static_assert(ftl::compose_digits(std::array<std::uint8_t, 10>{1,2,3,4,5,6,7,8,9,0})[9] == '0', "compose_digits({1,2,3,4,5,6,7,8,9,0}[9]");

/*
 * from_digits
 */
static_assert(ftl::from_digits(ftl::parse_digits("1234567890")) == 1234567890);
static_assert(ftl::from_digits<8>(ftl::parse_digits<8>("147625")) == 0147625);
static_assert(ftl::from_digits<16>(ftl::parse_digits<16>("FFED56")) == 0xFFED56);
static_assert(ftl::from_digits<64>(ftl::parse_digits<64>("y5I")) == 208456);

/*
 * to_digits
 */

// Base 8
static_assert(ftl::to_digits<8>(0147625).size() == 11);
static_assert(ftl::to_digits<8>(0147625)[0] == '5');
static_assert(ftl::to_digits<8>(0147625)[1] == '2');
static_assert(ftl::to_digits<8>(0147625)[2] == '6');
static_assert(ftl::to_digits<8>(0147625)[3] == '7');
static_assert(ftl::to_digits<8>(0147625)[4] == '4');
static_assert(ftl::to_digits<8>(0147625)[5] == '1');
static_assert(ftl::to_digits<8>(0147625)[6] == 0);
static_assert(ftl::to_digits<8>(0147625)[7] == 0);
static_assert(ftl::to_digits<8>(0147625)[8] == 0);
static_assert(ftl::to_digits<8>(0147625)[9] == 0);
static_assert(ftl::to_digits<8>(0147625)[10] == 0);

// Base 10
static_assert(ftl::to_digits(1234567890).size() == 10);
static_assert(ftl::to_digits(1234567890)[0] == '0');
static_assert(ftl::to_digits(1234567890)[1] == '9');
static_assert(ftl::to_digits(1234567890)[2] == '8');
static_assert(ftl::to_digits(1234567890)[3] == '7');
static_assert(ftl::to_digits(1234567890)[4] == '6');
static_assert(ftl::to_digits(1234567890)[5] == '5');
static_assert(ftl::to_digits(1234567890)[6] == '4');
static_assert(ftl::to_digits(1234567890)[7] == '3');
static_assert(ftl::to_digits(1234567890)[8] == '2');
static_assert(ftl::to_digits(1234567890)[9] == '1');

// Base 16
static_assert(ftl::to_digits<16>(0xFFED56).size() == 8);
static_assert(ftl::to_digits<16>(0xFFED56)[0] == '6');
static_assert(ftl::to_digits<16>(0xFFED56)[1] == '5');
static_assert(ftl::to_digits<16>(0xFFED56)[2] == 'D');
static_assert(ftl::to_digits<16>(0xFFED56)[3] == 'E');
static_assert(ftl::to_digits<16>(0xFFED56)[4] == 'F');
static_assert(ftl::to_digits<16>(0xFFED56)[5] == 'F');
static_assert(ftl::to_digits<16>(0xFFED56)[6] == 0);
static_assert(ftl::to_digits<16>(0xFFED56)[7] == 0);

// Base 64
static_assert(ftl::to_digits<64>(208456).size() == 6);
static_assert(ftl::to_digits<64>(208456)[0] == 'I');
static_assert(ftl::to_digits<64>(208456)[1] == '5');
static_assert(ftl::to_digits<64>(208456)[2] == 'y');
static_assert(ftl::to_digits<64>(208456)[3] == 0);
static_assert(ftl::to_digits<64>(208456)[4] == 0);
static_assert(ftl::to_digits<64>(208456)[5] == 0);

#endif//FTL_RADIX_HH