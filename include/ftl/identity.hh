#ifndef FTL_IDENTITY_HH
#define FTL_IDENTITY_HH

namespace ftl {

/*
 * identity
 */
template<typename V, V VALUE>
struct identity {
    static constexpr V value = VALUE;
};

}

#endif//FTL_IDENTITY_HH