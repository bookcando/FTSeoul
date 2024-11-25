#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename typeA>
class Array {
    private:
        typeA *_array;
        size_t _length;

    public:
        Array();
        Array(const Array &copy);
        // Array<typeA> &operator=(const Array<typeA> &copy);
        Array<typeA> &operator=(const Array<typeA> &copy);
        ~Array();

        Array(unsigned int n);
        size_t size() const;
        typeA &operator[](size_t index);
        void printArray();
};

template <typename typeA>
Array<typeA>::Array() {
    _array = new typeA[0];
    _length = 0;
}

template <typename typeA>
Array<typeA>::Array(const Array &copy) {
    _array = new typeA[copy._length];
    _length = copy._length;
    for (size_t i = 0; i < _length; i++) {
        _array[i] = copy._array[i];
    }
}

template <typename typeA>
Array<typeA> &Array<typeA>::operator=(const Array<typeA> &copy) {
    if (this == &copy) {
        return *this;
    }
    if (_array) {
        delete[] _array;
        _array = 0;
    }
    _array = new typeA[copy._length];
    _length = copy._length;
    for (size_t i = 0; i < _length; i++) {
        _array[i] = copy._array[i];
    }
    return *this;
}

template <typename typeA>
Array<typeA>::~Array() {
    delete[] _array;
}

template <typename typeA>
Array<typeA>::Array(unsigned int n) {
    _array = new typeA[n];
    _length = n;
    for (size_t i = 0; i < n; i++) {
        _array[i] = typeA();
    }
}

template <typename typeA>
size_t Array<typeA>::size() const {
    return _length;
}

template <typename typeA>
typeA &Array<typeA>::operator[](size_t index) {
    if (index >= _length) {
        throw std::exception();
    }
    return _array[index];
}

template <typename typeA>
void Array<typeA>::printArray() {
    try {
        for (size_t i = 0; i < _length; i++) {
            std::cout << "array[" << i << "] = " << _array[i] << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "printArray exception" << std::endl;
    }
}

#endif
