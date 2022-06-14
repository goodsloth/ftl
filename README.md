# ftl
Faster Than Light

C++17 Compile Time Template Header Library

---

## bigint
Multiprecision Big Integer

```c++
#include <ftl/bigint.hh>

// Maximum 256 bit unsigned integer in Base 16
// Use '_16' after a base 16 number to parse it into a 'ftl::bigint'
constexpr auto bigint256_base16
    = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF_16;

// Maximum 256 bit unsigned integer in Base 10
// Use '_10' after a base 10 number to parse it into a 'ftl::bigint'
constexpr auto bigint256_base10
    = 115792089237316195423570985008687907853269984665640564039457584007913129639935_10;

// Verify the highest set bit is the 256th
static_assert(bigint256_base10.highest_bit == 256);

// Multiply the two 256 bit unsigned integers into a 512 bit integer
constexpr auto bigint512 = bigint256_base10 * bigint256_base16;

// Verify the highest set bit is the 512th
static_assert(bigint512.highest_bit() == 512);
```

## radix
Multiple Radix Numeric Composing & Parsing

```c++
#include <ftl/radix.hh>

// Parse Base 10 String and convert to Integer
static_assert(ftl::from_digits(ftl::parse_digits("1234567890")) == 1234567890)

// Parse Base 8 String and convert to Integer
static_assert(ftl::from_digits<8>(ftl::parse_digits<8>("147625")) == 0147625);

// Parse Base 16 String and convert to Integer
static_assert(ftl::from_digits<16>(ftl::parse_digits<16>("FFED56")) == 0xFFED56);

// Parse Base 64 String and convert to Integer
static_assert(ftl::from_digits<64>(ftl::parse_digits<64>("y5I")) == 208456);
```