#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap1("claptrap1");
    ClapTrap claptrap2("claptrap2");
    ClapTrap claptrap3("claptrap3");
    ClapTrap claptrap4(claptrap1);

    claptrap3 = claptrap2;

    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    claptrap2.takeDamage(0);
    claptrap1.attack("claptrap2");
    std::cout << std::endl;

    claptrap1.beRepaired(10);
    claptrap1.takeDamage(0);
    claptrap2.beRepaired(10);

    ClapTrap claptrap5("claptrap5");
    std::cout << "\na rock is falling..." << std::endl << std::endl;
    claptrap5.takeDamage(4294967295);
    claptrap5.takeDamage(4294967295);
    
    ClapTrap claptrap6("claptrap6");
    std::cout << "\nhp overflow-ing elixir is in front of claptrap6" << std::endl << std::endl;
    claptrap6.beRepaired(4294967295);
    claptrap6.beRepaired(4294967285);
}
