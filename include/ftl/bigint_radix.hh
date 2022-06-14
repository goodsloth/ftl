#ifndef FTL_BIGINT_RADIX_HH
#define FTL_BIGINT_RADIX_HH

#include <ftl/identity.hh>
#include <ftl/radix.hh>

#include <cstdint>

namespace ftl {
namespace impl {

/*
 * required_bits_radix (Generic)
 */
template<std::size_t RADIX, std::size_t DIGITS>
struct required_bits_radix :
    identity<std::size_t, 0>
{};

/*
 * required_bits_radix (Base 8)
 */
template<std::size_t DIGITS>
struct required_bits_radix<8, DIGITS> :
    identity<std::size_t, DIGITS * 3>
{};

/*
 * required_bits_radix (Base 10)
 */
template<std::size_t DIGITS>
struct required_bits_radix<10, DIGITS> :
    identity<
        std::size_t,
        1 + static_cast<std::size_t>(
            static_cast<double>(DIGITS) *
            3.32192809488736234787
        )
    >
{};

/*
 * required_bits_radix (Base 16)
 */
template<std::size_t DIGITS>
struct required_bits_radix<16, DIGITS> :
    identity<std::size_t, DIGITS * 4>
{};

/*
 * required_bits_radix (Base 64)
 */
template<std::size_t DIGITS>
struct required_bits_radix<64, DIGITS> :
    identity<std::size_t, DIGITS * 6>
{};

} //namespace impl

/*
 * from_digits
 */
template<typename T, std::uint8_t RADIX = 10, typename DIGIT = std::uint8_t, size_t INPUT_LENGTH>
constexpr auto from_digits(const std::array<DIGIT, INPUT_LENGTH> digits) {
    using OverflowType = typename impl::bigint_datatype<T>::overflow_type;
    constexpr auto BITS = impl::required_bits_radix<RADIX, INPUT_LENGTH>::value;

    std::array<T, impl::required_elements<T, BITS>::value> result = {};
    for (size_t i = 0; i < INPUT_LENGTH; ++i) {
        OverflowType carry = zero<OverflowType>::value;
        for (size_t j = 0; j < result.size(); ++j) {
            OverflowType product = add(multiply(static_cast<OverflowType>(result[j]), static_cast<OverflowType>(RADIX)),
                                       carry);
            OverflowType low = product & std::numeric_limits<T>::max();
            carry = product >> std::numeric_limits<T>::digits;
            result[j] = low;
        }
        carry = digits[i];
        for (size_t j = 0; j < result.size(); ++j) {
            OverflowType sum = add(static_cast<OverflowType>(result[j]), carry);
            OverflowType low = sum & std::numeric_limits<T>::max();
            carry = sum >> std::numeric_limits<T>::digits;
            result[j] = low;
        }
    }
    return bigint<BITS, T>{ result };
}

/*
 * to_digits
 */
// TODO

namespace _ {

/*
 * _10 (Base 10 User-Defined-Literal)
 */
template<char... DIGITS>
constexpr auto operator "" _10() {
    return from_digits<std::uint32_t>(parse_digits_base10<DIGITS...>());
}

/*
 * _16 (Base 16 User-Defined-Literal)
 */
template<char... DIGITS>
constexpr auto operator "" _16() {
    return from_digits<std::uint32_t, 16>(parse_digits_base16<DIGITS...>());
}

}//namespace _
}//namespace ftl

/*
 * required_bits_radix (Base 8)
 */
static_assert(ftl::impl::required_bits_radix<8, 2>::value == 6);
static_assert(ftl::impl::required_bits_radix<8, 3>::value == 9);
static_assert(ftl::impl::required_bits_radix<8, 8>::value == 24);

/*
 * required_bits_radix (Base 10)
 */
static_assert(ftl::impl::required_bits_radix<10, 2>::value == 7);
static_assert(ftl::impl::required_bits_radix<10, 4>::value == 14);
static_assert(ftl::impl::required_bits_radix<10, 9>::value == 30);

/*
 * required_bits_radix (Base 16)
 */
static_assert(ftl::impl::required_bits_radix<16, 2>::value == 8);
static_assert(ftl::impl::required_bits_radix<16, 8>::value == 32);
static_assert(ftl::impl::required_bits_radix<16, 32>::value == 128);

/*
 * required_bits_radix (Base 64)
 */
static_assert(ftl::impl::required_bits_radix<64, 2>::value == 12);
static_assert(ftl::impl::required_bits_radix<64, 8>::value == 48);
static_assert(ftl::impl::required_bits_radix<64, 64>::value == 384);

/*
 * from_digits
 */
static_assert(ftl::from_digits<std::uint32_t>(ftl::parse_digits("1234567890"))[0] == 1234567890);
static_assert(ftl::from_digits<std::uint32_t>(ftl::parse_digits("340282366920938463463374607431768211455"))[0] == 0xFFFFFFFF);
static_assert(ftl::from_digits<std::uint32_t>(ftl::parse_digits("340282366920938463463374607431768211455"))[1] == 0xFFFFFFFF);
static_assert(ftl::from_digits<std::uint32_t>(ftl::parse_digits("340282366920938463463374607431768211455"))[2] == 0xFFFFFFFF);
static_assert(ftl::from_digits<std::uint32_t>(ftl::parse_digits("340282366920938463463374607431768211455"))[3] == 0xFFFFFFFF);
static_assert(ftl::from_digits<std::uint32_t>(ftl::parse_digits("340282366920938463463374607431768211455")).size() == 5);
static_assert(ftl::from_digits<std::uint32_t, 16>(ftl::parse_digits<16>("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"))[0] == 0xFFFFFFFF);
static_assert(ftl::from_digits<std::uint32_t, 16>(ftl::parse_digits<16>("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"))[1] == 0xFFFFFFFF);
static_assert(ftl::from_digits<std::uint32_t, 16>(ftl::parse_digits<16>("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"))[2] == 0xFFFFFFFF);
static_assert(ftl::from_digits<std::uint32_t, 16>(ftl::parse_digits<16>("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"))[3] == 0xFFFFFFFF);
static_assert(ftl::from_digits<std::uint32_t, 16>(ftl::parse_digits<16>("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF")).size() == 4);

/*
 * 'ftl::_' (User-Defined-Literal namespace)
 */
using namespace ftl::_;

/*
 * _10 (Base 10 User-Defined-Literal)
 */
// 128 bit max
static_assert(340282366920938463463374607431768211455_10[0] == 0xFFFFFFFF);
static_assert(340282366920938463463374607431768211455_10[1] == 0xFFFFFFFF);
static_assert(340282366920938463463374607431768211455_10[2] == 0xFFFFFFFF);
static_assert(340282366920938463463374607431768211455_10[3] == 0xFFFFFFFF);
static_assert((340282366920938463463374607431768211455_10).size() == 5);
static_assert((340282366920938463463374607431768211455_10).bits == 130);
static_assert((340282366920938463463374607431768211455_10).count == 5);
static_assert((340282366920938463463374607431768211455_10).highest_bit() == 128);

// 256 bit max
static_assert(115792089237316195423570985008687907853269984665640564039457584007913129639935_10[0] == 0xFFFFFFFF);
static_assert(115792089237316195423570985008687907853269984665640564039457584007913129639935_10[1] == 0xFFFFFFFF);
static_assert(115792089237316195423570985008687907853269984665640564039457584007913129639935_10[2] == 0xFFFFFFFF);
static_assert(115792089237316195423570985008687907853269984665640564039457584007913129639935_10[3] == 0xFFFFFFFF);
static_assert(115792089237316195423570985008687907853269984665640564039457584007913129639935_10[4] == 0xFFFFFFFF);
static_assert(115792089237316195423570985008687907853269984665640564039457584007913129639935_10[5] == 0xFFFFFFFF);
static_assert(115792089237316195423570985008687907853269984665640564039457584007913129639935_10[6] == 0xFFFFFFFF);
static_assert(115792089237316195423570985008687907853269984665640564039457584007913129639935_10[7] == 0xFFFFFFFF);
static_assert((115792089237316195423570985008687907853269984665640564039457584007913129639935_10).size() == 9);
static_assert((115792089237316195423570985008687907853269984665640564039457584007913129639935_10).bits == 260);
static_assert((115792089237316195423570985008687907853269984665640564039457584007913129639935_10).count == 9);
static_assert((115792089237316195423570985008687907853269984665640564039457584007913129639935_10).highest_bit() == 256);

/*
 * _16 (Base 16 User-Defined-Literal)
 */
static_assert(0xFFAADF_16[0] == 0x00FFAADF);
static_assert((0xFFAADF_16).size() == 1);
static_assert(0x1234567890ABCDEF1234567890abcdef_16[0] == 0x90ABCDEF);
static_assert(0x1234567890ABCDEF1234567890abcdef_16[1] == 0x12345678);
static_assert(0x1234567890ABCDEF1234567890abcdef_16[2] == 0x90ABCDEF);
static_assert(0x1234567890ABCDEF1234567890abcdef_16[3] == 0x12345678);
static_assert((0x1234567890ABCDEF1234567890abcdef_16).size() == 4);

#endif//FTL_BIGINT_RADIX_HH