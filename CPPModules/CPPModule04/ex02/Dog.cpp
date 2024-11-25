#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default Constructor called" << std::endl;
    type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    type = copy.type;
    this->brain = new Brain(*(copy.brain));
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this == &copy)
        return (*this);
    type = copy.type;
    *(this->brain) = *(copy.brain);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "WANG WANG" << std::endl;
}
