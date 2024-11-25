#include "Character.hpp"

Character::Character() : _name("Missing")
{
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = 0; // empty at construction
    }
}

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = 0; // empty at construction
    }
}

Character::Character(const Character &copy)
{
    //New Character = empty already
    _name = copy._name;
    for (int i = 0; i < 4; i++)
    {
        if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone(); //copy construct -> deep-copy their inventory
        else
            _inventory[i] = 0; //empty at construction
    }
}

Character &Character::operator=(const Character &copy)
{
    if (this == &copy)
        return (*this);
    _name = copy._name;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i]; //delete this->inventory[i] first
        _inventory[i] = 0; //empty this->inventory[i]
        if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone(); //copy operator -> deep-copy their inventory
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i]; //delete all materia in inventory
        // std::cout << "Materia deleted : character" << std::endl;
    }
}

std::string const &Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    if (m == 0)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == 0)
        {
            _inventory[i] = m;
            return ;
        }
    }
    // std::cout << "Character " << _name << ": Materia equip failed" << std::endl;
    delete m;
    // main pass : "Dynamically + Newly allocated new Ice and Cure"
    // -> delete them if i can't equip
}

void Character::unequip(int idx)
{
    if (0 <= idx && idx < 4)
    {
        if (_inventory[idx] != 0)
        {
            Waste::waste_add(_inventory[idx]);
            _inventory[idx] = 0; //not delete the materia
        }
        _inventory[idx] = 0; //not delete the materia
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (0 <= idx && idx < 4)
    {
        if (_inventory[idx] != 0)
        {
            _inventory[idx]->use(target);
        }
        else
            std::cout << "* " <<_name << " : slot " << idx << " is empty *" << std::endl;
    }
}
