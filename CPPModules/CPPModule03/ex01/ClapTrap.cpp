#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "NONAME";
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "ClapTrap \"" << this->name << "\" has made" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "ClapTrap \"" << this->name << "\" has made" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    this->name = copy.name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    std::cout << "ClapTrap \"" << this->name << "\" has made and copied" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    this->name = copy.name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    std::cout << "ClapTrap \"" << this->name << "\" has copied" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap \"" << this->name << "\" has destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hit_points == 0)
    {
        std::cout << "ClapTrap \"" << this->name << "\" is already dead" << std::endl;
        return ;
    }
    else if (this->energy_points == 0)
    {
        std::cout << "ClapTrap \"" << this->name << "\" has no energy to attack" << std::endl;
        return ;
    }
    else
    {
        std::cout << "ClapTrap \"" << this->name << "\" attacks \"" << target << "\", causing " << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points -= 1;
        return ;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points == 0)
    {
        std::cout << "ClapTrap \"" << this->name << "\" is already dead" << std::endl;
        return ;
    }
    else if (this->hit_points < amount)
    {
        std::cout << "ClapTrap \"" << this->name << "\" takes " << amount << " points of damage!" << std::endl;
        this->hit_points = 0;
    }
    else
    {
        std::cout << "ClapTrap \"" << this->name << "\" takes " << amount << " points of damage!" << std::endl;
        this->hit_points -= amount;
        return ;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points == 0)
    {
        std::cout << "ClapTrap \"" << this->name << "\" is already dead" << std::endl;
        return ;
    }
    else if (this->energy_points == 0)
    {
        std::cout << "ClapTrap \"" << this->name << "\" has no energy to be repaired" << std::endl;
        return ;
    }
    else if (amount == 0)
    {
        std::cout << "ClapTrap \"" << this->name << "\" has not repaired" << std::endl;
        return ;
    }
    else if ((amount + this->hit_points) <= this->hit_points)
    {
        std::cerr << "beRapaired : invalid input" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap \"" << this->name << "\" has repaired " << amount << " hit points!" << std::endl;
        this->hit_points += amount;
        this->energy_points -= 1;
        return ;
    }
}
