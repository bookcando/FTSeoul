#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->name = "NONAME";
    this->ClapTrap::name = this->name + "_clap_name";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap \"" << this->name << "\" has made" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
    this->name = name;
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap \"" << this->name << "\" has made" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(copy.ClapTrap::name), ScavTrap(copy.ClapTrap::name), FragTrap(copy.ClapTrap::name)
{
    this->name = copy.name;
    this->ClapTrap::name = copy.ClapTrap::name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    std::cout << "DiamondTrap \"" << this->name << "\" has made and copied" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    this->name = copy.name;
    this->ClapTrap::name = copy.ClapTrap::name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    std::cout << "DiamondTrap \"" << this->name << "\" has copied" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap \"" << this->name << "\" has destroyed" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name : " << this->name << std::endl;
    std::cout << "ClapTrap name    : " << this->ClapTrap::name << std::endl;
}
