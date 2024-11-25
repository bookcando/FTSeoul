#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <exception>

class RPN {
    private:
        std::stack<long long> _stack;
        std::string     _input;
        RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& copy);

        void calculateAdd();
        void calculateSub();
        void calculateMul();
        void calculateDiv();
        void checkValidity(const std::string &token);
        void putStack(std::string token);

    public:
        explicit RPN(const std::string& input);
        ~RPN();

        class DivisionByZeroException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class InvalidInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class OverUnderflowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

#endif
