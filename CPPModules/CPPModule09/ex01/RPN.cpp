#include "RPN.hpp"
#include "limits"

void RPN::putStack(std::string token) {
    std::stringstream ss(token);
    long long n;
    ss >> n;
    _stack.push(n);
}

RPN::RPN(const std::string& input) : _input(input) {
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        checkValidity(token);

        if (token == "+") {
            calculateAdd();
        } else if (token == "-") {
            calculateSub();
        } else if (token == "*") {
            calculateMul();
        } else if (token == "/") {
            calculateDiv();
        } else {
            putStack(token);
        }
    }
    if (_stack.size() != 1) {
        throw InvalidInputException();
    }
    std::cout << _stack.top() << std::endl;
}

RPN::~RPN() {
}

void RPN::calculateAdd() {
    long long b = _stack.top();
    _stack.pop();
    long long a = _stack.top();
    _stack.pop();

    if (b > 0 && a > std::numeric_limits<long long>::max() - b)
        throw OverUnderflowException();
    else if (b < 0 && a < std::numeric_limits<long long>::min() - b)
        throw OverUnderflowException();

    _stack.push(a + b);
}

void RPN::calculateSub() {
    long long b = _stack.top();
    _stack.pop();
    long long a = _stack.top();
    _stack.pop();

    if (b > 0 && a < std::numeric_limits<long long>::min() + b)
        throw OverUnderflowException();
    else if (b < 0 && a > std::numeric_limits<long long>::max() + b)
        throw OverUnderflowException();

    _stack.push(a - b);
}

static bool checkMulOverflow(long long a, long long b) {

    if (a == 0 || b == 0)
        return false;

    if (a > 0) {
        if (b > 0) {
            if (a > std::numeric_limits<long long>::max() / b)
                return true;
        }
        else {
            if (b < std::numeric_limits<long long>::min() / a)
                return true;
        }
    }
    else {
        if (b > 0) {
            if (a < std::numeric_limits<long long>::min() / b)
                return true;
        }
        else {
            if (b < std::numeric_limits<long long>::max() / a)
                return true;
        }
    }
    return false;
}

void RPN::calculateMul() {
    long long b = _stack.top();
    _stack.pop();
    long long a = _stack.top();
    _stack.pop();

    if (checkMulOverflow(a, b))
        throw OverUnderflowException();

    _stack.push(a * b);
}

void RPN::calculateDiv() {
    long long b = _stack.top();
    _stack.pop();
    long long a = _stack.top();
    _stack.pop();
    if (b == 0) {
        throw DivisionByZeroException();
    }
    if (a == std::numeric_limits<long long>::min() && b == -1) {
        throw OverUnderflowException();
    }
    _stack.push(a / b);
}

void RPN::checkValidity(const std::string &token) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        if (_stack.size() < 2) {
            throw InvalidInputException();
        }
    }
    else {
        if (token.size() == 0) {
            throw InvalidInputException();
        }
        std::stringstream ss(token);
        long long n;
        ss >> n;
        if (ss.fail() || !ss.eof()) {
            throw InvalidInputException();
        }
        if (n < -9 || n > 9) {
            throw InvalidInputException();
        }
    }
}

const char* RPN::DivisionByZeroException::what() const throw() {
    return "Division by zero";
}

const char* RPN::InvalidInputException::what() const throw() {
    return "Invalid input";
}

const char* RPN::OverUnderflowException::what() const throw() {
    return "Overflow/Underflow";
}