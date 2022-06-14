#ifndef FTL_COMPARISON_HH
#define FTL_COMPARISON_HH

#include <ftl/identity.hh>

namespace ftl {

/*
 * Equality (A == B)
 */

template<typename V>
constexpr bool is_equal(V A, V B) {
    return A == B;
}

/*
 * Inequality (A != B)
 */
template<typename V>
constexpr bool is_not_equal(V A, V B) {
    return A != B;
}

/*
 * Less Than (A < B)
 */
template<typename V>
constexpr bool is_less(V A, V B) {
    return A < B;
}

/*
 * Less Than Or Equal To (A <= B)
 */
template<typename V>
constexpr bool is_less_or_equal(V A, V B) {
    return A <= B;
}

/*
 * Greater Than  (A > B)
 */
template<typename V>
constexpr bool is_greater(V A, V B) {
    return A > B;
}

/*
 * Less Than Or Equal To (A <= B)
 */

template<typename V>
constexpr bool is_greater_or_equal(V A, V B) {
    return A >= B;
}

}

#endif//FTL_COMPARISON_HH