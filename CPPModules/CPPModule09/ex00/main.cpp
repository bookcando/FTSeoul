#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {


    if (argc > 2) {
        std::cout << "Error: too many arguments" << std::endl;
        return 1;
    }
    else if (argc < 2) {
        std::cout << "Error: input file required" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange exchange("data.csv");
        exchange.rateCalculator(argv[1]);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
