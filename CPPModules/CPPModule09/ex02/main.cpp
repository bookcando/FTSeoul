
#include <iostream>
#include <sstream>
#include "PmergeMe.hpp"

int main(int argc, const char **argv) {

    if (argc < 2) {
        std::cout << "Error: input required"<< std::endl;
        return 1;
    }
    if (argc > 1000000) {
        std::cout << "Error: too many arguments" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.parseInput(argv);
        sorter.printVectorData("Before: ");
        sorter.sortData();
        if (sorter.checkSorted() == false) {
            std::cout << "Error: list and vector results are not the same" << std::endl;
            return 1;
        }
        sorter.printVectorData("After : ");
        sorter.printResults();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
