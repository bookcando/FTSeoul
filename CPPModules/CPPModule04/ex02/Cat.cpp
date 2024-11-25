#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default Constructor called" << std::endl;
    type = "Cat";
    this->brain = new Brain();   
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    type = copy.type;
    this->brain = new Brain(*(copy.brain));
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this == &copy)
        return (*this);
    type = copy.type;
    *(this->brain) = *(copy.brain);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "MYA MEOW" << std::endl;
}
