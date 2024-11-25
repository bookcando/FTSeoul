#include "Span.hpp"

int main(void) {
    Span sp = Span(5);
    try {
        sp.shortestSpan();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    sp.addNumber(5);
    try {
        sp.shortestSpan();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "-------------------------" << std::endl;

    try {
        sp.addNumber(25);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;


    Span temp1(50000);
    temp1.fillRandomNumber();
    std::cout << "size : " << temp1.getSize() << std::endl;
    std::cout << "short: " << temp1.shortestSpan() << std::endl;
    std::cout << "long : " << temp1.longestSpan() << std::endl;
    std::cout << "-------------------------" << std::endl;
    try {
        temp1.addNumber(25);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::vector<int> tempVec;
    for (int i = 0; i < 10000; i++)
    {
        tempVec.push_back(i);
    }

    Span temp2(20000);
    temp2.addNumber(tempVec.begin(), tempVec.end());
    std::cout << "size : " << temp2.getSize() << std::endl;
    std::cout << "short: " << temp2.shortestSpan() << std::endl;
    std::cout << "long : " << temp2.longestSpan() << std::endl;
    std::cout << "-------------------------" << std::endl;

    return 0;
}