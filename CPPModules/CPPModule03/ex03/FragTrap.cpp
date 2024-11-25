#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->name = "NONAME";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap \"" << this->name << "\" has made" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap \"" << this->name << "\" has made" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy.name)
{
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    std::cout << "FragTrap \"" << this->name << "\" has made and copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    this->name = copy.name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    std::cout << "FragTrap \"" << this->name << "\" has copied" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap \"" << this->name << "\" has destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->hit_points == 0)
    {
        std::cout << "FragTrap \"" << this->name << "\" is already dead" << std::endl;
        return ;
    }
    else if (this->energy_points == 0)
    {
        std::cout << "FragTrap \"" << this->name << "\" has no energy" << std::endl;
        return ;
    }
    else
    {
        std::cout << "FragTrap \"" << this->name << "\" has requested high fives!" << std::endl;
    }
}
