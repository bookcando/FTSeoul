#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: one input required" << std::endl;
        return 1;
    }
    
    try {
        RPN rpn(argv[1]);
    } 
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
