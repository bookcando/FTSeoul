#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Default Constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << "WrongCat Copy Constructor called" << std::endl;
    type = copy.type;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    type = copy.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WOEM WOEM" << std::endl;
}
