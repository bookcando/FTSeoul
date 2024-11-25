#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "ClapTrap/ScavTrap/FragTrap/DiamondTrap construction test" << std::endl;
    ClapTrap claptrap1("claptrap1");
    std::cout << std::endl;
    ScavTrap scavtrap1("scavtrap1");
    std::cout << std::endl;
    FragTrap fragtrap1("fragtrap1");
    std::cout << std::endl;
    DiamondTrap diamondtrap1("diamondtrap1");
    std::cout << std::endl;


    diamondtrap1.whoAmI();
    diamondtrap1.attack("scavtrap1");
    scavtrap1.attack("diamondtrap1");
    fragtrap1.attack("diamondtrap1");
    diamondtrap1.highFivesGuys();
    diamondtrap1.guardGate();
    std::cout << std::endl;


    std::cout << std::endl << std::endl;
    return (0);
}
