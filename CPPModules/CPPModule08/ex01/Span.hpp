#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <climits>
#include <algorithm>

class Span
{
    private:
        Span();
        unsigned int _N;
        unsigned int _size;
        std::vector<int> _vector;

    public:
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();
        Span(unsigned int N);

        void fillRandomNumber();
        void addNumber(int number);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        size_t getSize() const;

        class OutOfRangeException : public std::exception
        { // over _N
            public:
                virtual const char *what() const throw();
        };

        class NoSpanException : public std::exception
        { // less than 2 numbers
            public:
                virtual const char *what() const throw();
        };
};

#endif
