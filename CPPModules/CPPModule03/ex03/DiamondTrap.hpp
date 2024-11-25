#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
    private :
        std::string name;
        DiamondTrap();

    public :
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &d);
        DiamondTrap &operator=(const DiamondTrap &d);
        ~DiamondTrap();
        void whoAmI();
};

#endif
