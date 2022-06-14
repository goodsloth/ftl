#include <ftl/bigint.hh>

#include <cstdio>
#include <iostream>

using namespace ftl;

// Maximum 256 bit unsigned integer in Base 16
constexpr auto bigint256_base16
    = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF_16;

// Maximum 256 bit unsigned integer in Base 10
constexpr auto bigint256_base10
    = 115792089237316195423570985008687907853269984665640564039457584007913129639935_10;

// Verify the highest set bit is the 256th
static_assert(bigint256_base10.highest_bit() == 256);

// Multiply the two 256 bit unsigned integers into a 512 bit integer
constexpr auto bigint512_a= bigint256_base10 * bigint256_base16;
constexpr auto bigint512_b= bigint256_base16 * bigint256_base10;

// Verify the highest set bit is the 512th
static_assert(bigint512_a.highest_bit() == 512);
static_assert(bigint512_b.highest_bit() == 512);

template<size_t BITS, typename T>
void print(bigint<BITS, T> a) {
    std::cout << a.bits << "," << a.highest_bit() << "," << a.count << "\n";
    for (size_t i = 0; i < a.count; i++) {
        std::cout << (a[i]) << ",";
    }
    std::cout << '\n';
}

int main()
{
    std::cout << (340282366920938463463374607431768211455_10).bits << "\n";
    print(340282366920938463463374607431768211455_10);
    print((115792089237316195423570985008687907853269984665640564039457584007913129639935_10));
    print(bigint256_base10);
    print(bigint256_base16);
    print(bigint512_a);
    print(bigint512_b);

    return 0;
}
