#include "Array.hpp"

// void leakcheck() {
//     system("leaks ex02 | grep leaked");
//     // system("leaks ex02");
// }


int main(void) {
    // atexit(leakcheck);

    int *a = new int();
    int *b = new int();
    std::cout << *a << std::endl;
    std::cout << *b << std::endl;
    delete a;
    delete b;

    Array<int> arrayA(5);
    Array<int> *arrayC = new Array<int>(5);
    Array<int> arrayD;
    // (void)arrayC;

    std::cout << "constructor test(initialization)" << std::endl;
    std::cout << "arrayA" << std::endl;
    arrayA.printArray();

    for (int i = 0; i < 5; i++) {
        arrayA[i] = i * i;
    }
    std::cout << "arrayA" << std::endl;
    arrayA.printArray();
    std::cout << "arrayC" << std::endl;
    (*arrayC).printArray();
    std::cout << "-------------------------" << std::endl << std::endl;

    std::cout << "copy constructor test" << std::endl;
    Array<int> arrayB(arrayA);
    std::cout << "arrayA" << std::endl;
    arrayA.printArray();
    std::cout << "arrayB" << std::endl;
    arrayB.printArray();
    std::cout << "arrayC" << std::endl;
    (*arrayC).printArray();
    std::cout << "-------------------------" << std::endl << std::endl;

    std::cout << "copy assignment test" << std::endl;
    ((*arrayC)) = arrayA;
    std::cout << "arrayA" << std::endl;
    arrayA.printArray();
    std::cout << "arrayB" << std::endl;
    arrayB.printArray();
    std::cout << "arrayC" << std::endl;
    (*arrayC).printArray();
    std::cout << "-------------------------" << std::endl << std::endl;

    std::cout << "value changing test" << std::endl;
    arrayA[0] = 100;
    arrayB[1] = 200;
    ((*arrayC))[2] = 300;
    try {
        arrayA[6] = 1000;
    }
    catch (std::exception &e) {
        std::cout << "exception caught" << std::endl;
    }
    std::cout << "arrayA" << std::endl;
    arrayA.printArray();
    std::cout << "arrayB" << std::endl;
    arrayB.printArray();
    std::cout << "arrayC" << std::endl;
    (*arrayC).printArray();

    std::cout << "-------------------------" << std::endl << std::endl;
    try {
        arrayD[0] = 100;
    }
    catch (std::exception &e) {
        std::cout << "exception caught" << std::endl;
    }


    delete arrayC;
}