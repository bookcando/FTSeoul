#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default Constructor called" << std::endl;
    type = "Animal";
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
    type = copy.type;
}

Animal &Animal::operator=(const Animal &copy)
{
    if (this == &copy)
        return (*this);
    type = copy.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Ani... animal~" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}
