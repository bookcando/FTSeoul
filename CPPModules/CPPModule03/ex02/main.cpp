#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "ClapTrap/ScavTrap/FragTrap construction test" << std::endl;
    ClapTrap claptrap1("claptrap1");
    ScavTrap scavtrap1("scavtrap1");
    FragTrap fragtrap1("fragtrap1");
    std::cout << std::endl;

    std::cout << "GENERAL TESTS" << std::endl;
    claptrap1.attack("scavtrap1");
    scavtrap1.takeDamage(0);
    scavtrap1.beRepaired(10);
    std::cout << std::endl;

    scavtrap1.attack("fragtrap1");
    fragtrap1.takeDamage(20);
    fragtrap1.beRepaired(10);
    std::cout << std::endl;

    std::cout << "101 attacks test" << std::endl;
    for (int i = 0; i < 101; i++)
    {
        fragtrap1.attack("scavtrap1");
        scavtrap1.takeDamage(20);
    }
    std::cout << "101 attack test (finished)"<< std::endl;
    std::cout << std::endl;

    std::cout << "scavtrap guard gate (0 hp) / fragtrap high fives guys (0 ep) test" << std::endl;
    scavtrap1.guardGate();
    fragtrap1.highFivesGuys();
    std::cout << std::endl;

    std::cout << "ScavTrap/FragTrap copy construction test" << std::endl;
    ScavTrap scavtrap2("scavtrap2");
    ScavTrap scavtrap3(scavtrap1);
    FragTrap fragtrap2("fragtrap2");
    FragTrap fragtrap3(fragtrap1);
    std::cout << std::endl;

    std::cout << "scavtrap guard gate (at 0 hp) / copy test" << std::endl;
    scavtrap3.guardGate();
    scavtrap3 = scavtrap2;
    scavtrap3.guardGate();
    std::cout << std::endl;

    std::cout << "fragtrap high fives guys (at 0 ep) / copy test" << std::endl;
    fragtrap3.highFivesGuys();
    fragtrap3 = fragtrap2;
    fragtrap3.highFivesGuys();
    std::cout << std::endl;







    return (0);
}
