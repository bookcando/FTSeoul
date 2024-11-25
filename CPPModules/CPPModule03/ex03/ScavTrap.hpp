#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
    protected :
        ScavTrap();

    public :
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &s);
        ScavTrap &operator=(const ScavTrap &s);
        ~ScavTrap();

        virtual void attack(const std::string &target);
        void guardGate();
};

#endif
