#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    //typename in front of T means
    //T is not a class or a variable, but a type
    if (iter == container.end())
    {
        throw std::exception();
    }
    return iter;
}
#endif
