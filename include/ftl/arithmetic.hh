#ifndef FTL_ARITHMETIC_HH
#define FTL_ARITHMETIC_HH

#include <ftl/comparison.hh>
#include <ftl/identity.hh>

namespace ftl {

/*
 * Magic Numbers
 */
template<typename V, typename... Args>
struct zero : identity<V, 0> {};

template<typename V, typename... Args>
struct one : identity<V, 1> {};

template<typename V, typename... Args>
struct two : identity<V, 2> {};

template<typename V, typename... Args>
struct three : identity<V, 3> {};

template<typename V, typename... Args>
struct ten : identity<V, 10> {};



/*
 * negate (-)
 */
template<typename V>
constexpr auto negate(V value) {
    return -value;
}

/*
 * absolute_value (||)
 */
template<typename V>
constexpr V absolute_value(V value) {
    return is_greater(value, zero<V>::value) ? value : negate(value);
}

/*
 * Mod (%)
 */
template<typename A, typename B>
constexpr auto modulo(A a, B b) {
    return a % b;
}

/*
 * add (a + b)
 */
template<typename A, typename B>
constexpr auto add(A a, B b) {
    return a + b;
}

/*
 * subtract (a - b)
 */
template<typename A, typename B>
constexpr auto subtract(A a, B b) {
    return a - b;
}

/*
 * multiply (a * b)
 */
template<typename A, typename B>
constexpr auto multiply(A a, B b) {
    return a * b;
}

/*
 * divide (a / b)
 */
template<typename A, typename B>
constexpr auto divide(A a, B b) {
    return a / b;
}

}

#endif//FTL_ARITHMETIC_HH