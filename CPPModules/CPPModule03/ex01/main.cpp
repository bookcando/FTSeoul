#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scavtrap1("scavtrap1");
    ScavTrap scavtrap2("scavtrap2");
    ScavTrap scavtrap3("scavtrap3");
    ScavTrap scavtrap4(scavtrap1);

    scavtrap4 = scavtrap2;

    std::cout << "51 attacks test" << std::endl;
    for (int i = 1; i <= 51; i++)
    {
        scavtrap1.attack("scavtrap2");
        scavtrap2.takeDamage(20);
    }
    std::cout << "51 attacks test (finished)" << std::endl << std::endl;

    scavtrap4 = scavtrap2;    
    scavtrap1.beRepaired(20);
    scavtrap3.attack("scavtrap2");
    scavtrap2.takeDamage(20);
    scavtrap1.guardGate();
    scavtrap2.guardGate();
    std::cout << std::endl;

    scavtrap3 = scavtrap1;
    scavtrap3.attack("scavtrap2");
    std::cout << std::endl;

    return (0);
}
