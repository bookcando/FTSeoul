#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename typeA, typename returnTypeOfFunction>
void iter(typeA *array, size_t length, returnTypeOfFunction function) {
    if (array == NULL || function == NULL || length == 0) {
        return;
    }
    for (size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}
// don't know what the function's return type is. (can be non-void)
// -> use template too.

template <typename typeA, typename returnTypeOfFunction>
void iter(const typeA *array, size_t length, returnTypeOfFunction function) {
    if (array == NULL || function == NULL || length == 0) {
        return;
    }
    for (size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}

template <typename typeA, typename returnTypeOfFunction>
void iter(volatile typeA *array, size_t length, returnTypeOfFunction function) {
    if (array == NULL || function == NULL || length == 0) {
        return;
    }
    for (size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}

template <typename typeA, typename returnTypeOfFunction>
void iter(const volatile typeA *array, size_t length, returnTypeOfFunction function) {
    if (array == NULL || function == NULL || length == 0) {
        return;
    }
    for (size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}
// need to consider "const" and "volatile".


template <typename typeA>
void printElement(const typeA element) {
    std::cout << element << std::endl;
}

template <typename typeA>
int addOneToValue(typeA &element) {
    element += 1;
    return element;
}

template <typename typeA>
typeA doubleTheValue(typeA &element) {
    element *= 2;
    return element;
}

#endif
