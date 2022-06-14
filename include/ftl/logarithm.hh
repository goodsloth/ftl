#ifndef FTL_LOGARITHM_HH
#define FTL_LOGARITHM_HH

#include <ftl/arithmetic.hh>

namespace ftl {

/*
 * identity
 */
template<typename V>
constexpr V logarithm(V base, V value) {
    if (is_equal(value, one<V>::value)) {
        return zero<V>::value;
    }
    V exponent = zero<V>::value;
    for (V result = base; is_less_or_equal(result, value); result = multiply(result, base)) {
        exponent = add(exponent, 1);
    }
    return exponent;
}

}//namespace ftl

static_assert(ftl::logarithm(2, 1) == 0, "Log2(1)");
static_assert(ftl::logarithm(2, 63) == 5, "Log2(63)");
static_assert(ftl::logarithm(2, 64) == 6, "Log2(64)");
static_assert(ftl::logarithm(2, 127) == 6, "Log2(127)");
static_assert(ftl::logarithm(2, 128) == 7, "Log2(127)");
static_assert(ftl::logarithm(5, 625) == 4, "Log5(625)");
static_assert(ftl::logarithm(16, 4096) == 3, "Log16(4096)");
static_assert(ftl::logarithm(10, 100000) == 5, "Log10(100000)");

#endif//FTL_LOGARITHM_HH