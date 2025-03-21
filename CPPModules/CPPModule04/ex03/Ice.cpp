#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria(copy.getType()) {}

Ice &Ice::operator=(const Ice &copy)
{
    if (this == &copy)
        return (*this);
    _type = copy.getType();
    return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
