#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// swap : regular + volatile
template <typename typeA>
void swap(typeA &a, typeA &b) {
    typeA temp = a;
    a = b;
    b = temp;
}

template <typename typeA>
void swap(volatile typeA &a, volatile typeA &b) {
    volatile typeA temp = a;
    a = b;
    b = temp;
}

// min + max : 
// just get the value, not the reference
template <typename typeA>
typeA min(typeA a, typeA b) {
    if (a < b)
        return a; //smaller
    return b;
}

template <typename typeA>
typeA max(typeA a, typeA b) {
    if (a > b)
        return a; //bigger
    return b;
}

#endif
