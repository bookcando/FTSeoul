#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria()
{
    _type = "Missing";
}

AMateria::AMateria(std::string const &type)
{
    _type = type;
}

AMateria::AMateria(const AMateria &copy)
{
    _type = copy._type;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
    if (this == &copy)
        return (*this);
    _type = copy.getType();
    return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
    return (_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* nothing happened to " << target.getName() << " *" << std::endl;
}
