#include "Span.hpp"


Span::Span() : _N(0), _size(0), _vector(0) {}

Span::Span(const Span &copy) : _N(copy._N), _size(copy._size) {
    for (unsigned int i = 0; i < copy._size; i++)
    {
        _vector.push_back(copy._vector[i]);
    }
}

Span &Span::operator=(const Span &copy) {
    if (this == &copy)
        return *this;
    _size = copy._size;
    _vector.clear();
    for (unsigned int i = 0; i < _size; i++)
    {
        _vector.push_back(copy._vector[i]);
    }
    return *this;
}

Span::~Span() {}

Span::Span(unsigned int N) : _N(N), _size(0) {}

void Span::addNumber(int number) {
    if (_size >= _N)
        throw OutOfRangeException();
    _vector.push_back(number);
    _size++;
}

int Span::shortestSpan() {
    if (_size < 2)
        throw NoSpanException();

    std::sort(_vector.begin(), _vector.end());
    int min = INT_MAX;
    for (unsigned int i = 0; i < _size - 1; i++)
    {
        if (_vector[i + 1] - _vector[i] < min)
            min = _vector[i + 1] - _vector[i];
    }
    return min;
}

int Span::longestSpan() {
    if (_size < 2)
        throw NoSpanException();

    #ifdef DEBUG
    std::cout << std::endl;
    std::cout << "max: " << *(std::max_element(_vector.begin(), _vector.end())) << std::endl;
    std::cout << "min: " << *(std::min_element(_vector.begin(), _vector.end())) << std::endl;
    #endif
    
    return ( \
    *(std::max_element(_vector.begin(), _vector.end())) \
    - *(std::min_element(_vector.begin(), _vector.end())));
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) { 
    while (begin != end && _size < _N)
    {
        addNumber(*begin);
        begin++;
    }
}

void Span::fillRandomNumber() {
    srand(time(NULL));
    for (unsigned int i = 0; i < _N; i++)
    {
        addNumber(rand());
    }
}

size_t Span::getSize() const {
    return _size;
}

const char *Span::NoSpanException::what() const throw() {
    return "Span::NoSpanException::Not enough elements";
}

const char *Span::OutOfRangeException::what() const throw() {
    return "Span::OutOfRangeException::Too many elements";
}

