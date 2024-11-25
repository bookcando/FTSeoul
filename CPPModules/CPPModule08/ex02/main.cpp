#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it1 = mstack.begin();
    MutantStack<int>::iterator ite1 = mstack.end();

    ++it1;
    std::cout << "value check : " << *it1 << std::endl;
    --it1;
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::stack<int> s1(mstack);

    std::cout << "-------------------------" << std::endl;

    std::vector<int> myvector;
    myvector.push_back(5);
    myvector.push_back(17);

    std::cout << myvector.back() << std::endl;

    myvector.pop_back();

    std::cout << myvector.size() << std::endl;

    myvector.push_back(3);
    myvector.push_back(5);
    myvector.push_back(737);
    //[...]
    myvector.push_back(0);

    std::vector<int>::iterator it2 = myvector.begin();
    std::vector<int>::iterator ite2 = myvector.end();

    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::vector<int> s2(myvector);

    std::cout << "-------------------------" << std::endl;

    std::list<int> mylist;
    mylist.push_back(5);
    mylist.push_back(17);

    std::cout << mylist.back() << std::endl;

    mylist.pop_back();

    std::cout << mylist.size() << std::endl;

    mylist.push_back(3);
    mylist.push_back(5);
    mylist.push_back(737);
    //[...]
    mylist.push_back(0);

    std::list<int>::iterator it3 = mylist.begin();
    std::list<int>::iterator ite3 = mylist.end();

    ++it3;
    --it3;
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }

    std::cout << "-------------------------" << std::endl;

    std::stack<int, std::list<int> > temp1;
    std::stack<int, std::vector<int> > temp2;
    std::stack<int, std::deque<int> > temp3;
    // std::stack<int, std::deque<float> > temp4;
    // compile error
    std::cout << "-------------------------" << std::endl;

    std::cout << "is mstack empty : " << mstack.empty() << std::endl;
    MutantStack<int> mstack2;
    std::cout << "is mstack2 empty : " << mstack2.empty() << std::endl;
    MutantStack<int>::iterator tempit = std::find(mstack.begin(), mstack.end(), 256);
    if (tempit == mstack.end())
    {
        std::cout << "find returned \"mstack.end()\"" << std::endl;
    }
    else
    {
        std::cout << "find returned the iterator" << std::endl;
    }
    tempit = std::find(mstack.begin(), mstack.end(), 5);
    if (tempit == mstack.end())
    {
        std::cout << "find returned \"mstack.end()\"" << std::endl;
    }
    else
    {
        std::cout << "find returned the iterator" << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    

    return 0;
}