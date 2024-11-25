#include "iter.hpp"
#include <iostream>

int addOneToValueInt(int &element) {
    element += 1;
    return element;
}
//adding one, with return type.

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string stringArray[] = {"one", "two", "three", "four", "five"};

    const int constIntArray[] = {1, 2, 3, 4, 5};
    const char constCharArray[] = {'a', 'b', 'c', 'd', 'e'};
    const float constFloatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    const std::string constStringArray[] = {"one", "two", "three", "four", "five"};

    volatile int volatileIntArray[] = {1, 2, 3, 4, 5};
    volatile char volatileCharArray[] = {'a', 'b', 'c', 'd', 'e'};
    volatile float volatileFloatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    const volatile int constVolatileIntArray[] = {1, 2, 3, 4, 5};
    const volatile char constVolatileCharArray[] = {'a', 'b', 'c', 'd', 'e'};
    const volatile float constVolatileFloatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    iter(intArray, 5, printElement<int>);
    iter(charArray, 5, printElement<char>);
    iter(floatArray, 5, printElement<float>);
    iter(stringArray, 5, printElement<std::string>);
    std::cout << "-------------------------" << std::endl;

    iter(constIntArray, 5, printElement<const int>);
    iter(constCharArray, 5, printElement<const char>);
    iter(constFloatArray, 5, printElement<const float>);
    iter(constStringArray, 5, printElement<const std::string>);
    std::cout << "-------------------------" << std::endl;

    iter(volatileIntArray, 5, printElement<volatile int>);
    iter(volatileCharArray, 5, printElement<volatile char>);
    iter(volatileFloatArray, 5, printElement<volatile float>);
    std::cout << "-------------------------" << std::endl;

    iter(constVolatileIntArray, 5, printElement<const volatile int>);
    iter(constVolatileCharArray, 5, printElement<const volatile char>);
    iter(constVolatileFloatArray, 5, printElement<const volatile float>);
    std::cout << "-------------------------" << std::endl;

    iter(intArray, 5, addOneToValue<int>);
    iter(charArray, 5, addOneToValue<char>);
    iter(floatArray, 5, addOneToValue<float>);
    // iter(stringArray, 5, addOneToValue<std::string>); //compile error

    iter(intArray, 5, doubleTheValue<int>);
    iter(charArray, 5, doubleTheValue<char>);
    iter(floatArray, 5, doubleTheValue<float>);
    // iter(stringArray, 5, doubleTheValue<std::string>); //compile error 
    std::cout << std::endl;

    // iter(constIntArray, 5, addOneToValue<const int>);
    // iter(constCharArray, 5, addOneToValue<const char>);
    // iter(constFloatArray, 5, addOneToValue<const float>);
    // iter(constStringArray, 5, addOneToValue<const std::string>);
    // all compile error

    iter(volatileIntArray, 5, addOneToValue<volatile int>);
    iter(volatileCharArray, 5, addOneToValue<volatile char>);
    iter(volatileFloatArray, 5, addOneToValue<volatile float>);
    // iter(volatileStringArray, 5, addOneToValue<volatile std::string>); //compile error

    // iter(constVolatileIntArray, 5, addOneToValue<const volatile int>);
    // iter(constVolatileCharArray, 5, addOneToValue<const volatile char>);
    // iter(constVolatileFloatArray, 5, addOneToValue<const volatile float>);
    // iter(constVolatileStringArray, 5, addOneToValue<const volatile std::string>);

    iter(intArray, 5, addOneToValueInt);
    printElement(intArray[0]);
    addOneToValueInt(intArray[0]);
    doubleTheValue(intArray[0]);
    printElement(intArray[0]);
    std::cout << "-------------------------" << std::endl;

    printElement(floatArray[1]);
    addOneToValue(floatArray[1]);
    doubleTheValue(floatArray[1]);
    printElement(floatArray[1]);
    std::cout << "-------------------------" << std::endl;

    charArray[2] = '0';
    printElement(charArray[2]);
    addOneToValue(charArray[2]);
    doubleTheValue(charArray[2]);
    printElement(charArray[2]);
    std::cout << "-------------------------" << std::endl;

    return 0;
}
