#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->name = "NONAME";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap \"" << this->name << "\" has made" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap \"" << this->name << "\" has made" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.name)
{
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    std::cout << "ScavTrap \"" << this->name << "\" has made and copied" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    this->name = copy.name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    std::cout << "ScavTrap \"" << this->name << "\" has copied" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap \"" << name << "\" has destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->hit_points == 0)
    {
        std::cout << "ScavTrap \"" << name << "\" is already dead" << std::endl;
        return ;
    }
    else if (this->energy_points == 0)
    {
        std::cout << "ScavTrap \"" << name << "\" has no energy to attack" << std::endl;
        return ;
    }
    else
    {
        std::cout << "ScavTrap \"" << name << "\" attacks \"" << target << "\", causing " << attack_damage << " points of damage!" << std::endl;
        this->energy_points -= 1;
    }
}

void ScavTrap::guardGate()
{
    if (this->hit_points == 0)
    {
        std::cout << "ScavTrap \"" << name << "\" is already dead" << std::endl;
        return ;
    }
    else if (this->energy_points == 0)
    {
        std::cout << "ScavTrap \"" << name << "\" has no energy to be in Gate Keeper mode" << std::endl;
        return ;
    }
    std::cout << "ScavTrap \"" << name << "\" is in Gate keeper mode" << std::endl;
}
