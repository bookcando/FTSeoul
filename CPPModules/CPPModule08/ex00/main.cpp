#include "easyfind.hpp"
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

int main(void) {
    std::vector<int> intVector;
    intVector.push_back(1);
    intVector.push_back(4);
    intVector.push_back(9);
    intVector.push_back(16);
    intVector.push_back(25);

    //what does regular find return?
    std::vector<int>::iterator temp = std::find(intVector.begin(), intVector.end(), 81);
    if (temp == intVector.end())
    {
        std::cout << "find returned \"intVector.end()\"" << std::endl;
    }
    else
    {
        std::cout << "find returned the iterator" << std::endl;
    }





    for (std::vector<int>::iterator iter = intVector.begin(); iter != intVector.end(); iter++)
    {
        std::cout << "Value: " << *iter << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    // std::vector<int>::iterator temp = easyfind(intVector, 4);
    temp = easyfind(intVector, 4);
    *temp = 10;
    for (std::vector<int>::iterator iter = intVector.begin(); iter != intVector.end(); iter++)
    {
        std::cout << "Value: " << *iter << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::deque<int> intDeque;
    intDeque.push_back(1);
    intDeque.push_back(4);
    intDeque.push_back(9);
    intDeque.push_back(16);
    intDeque.push_back(25);

    for (std::deque<int>::iterator iter = intDeque.begin(); iter != intDeque.end(); iter++)
    {
        std::cout << "Value: " << *iter << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::deque<int>::iterator temp2 = easyfind(intDeque, 4);
    *temp2 = 10;
    for (std::deque<int>::iterator iter = intDeque.begin(); iter != intDeque.end(); iter++)
    {
        std::cout << "Value: " << *iter << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    // temp2 = easyfind(intDeque, 81);
    // exception

}