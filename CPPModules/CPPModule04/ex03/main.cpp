#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Waste.hpp"
#include <iostream>

// void leaks_exit()
// {
//     system("leaks ex03 | grep leaked");
// }

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    //since it makes "new Ice() for learnMateria... (see learnMateria)"
    //ALWAYS PUT IN WITH "new" keyword

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

//Additional
    std::cout << "ADDITIONAL TEST" << std::endl;

    std::cout << "Simple Test" << std::endl;
    ICharacter* susan = new Character("susan");

    me->unequip(0);
    me->use(0, *susan);
    me->use(1, *susan);

//equip + equip full slot
    std::cout << "TEST==equip + equip full slot" << std::endl;
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("cure"));

//unequip + unequip empty slot
    std::cout << "TEST==unequip + unequip empty slot" << std::endl;
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->unequip(0);
    me->unequip(0);
    me->unequip(1);
    me->unequip(1);
    me->unequip(2);
    me->unequip(2);
    me->unequip(3);
    me->unequip(3);
    me->unequip(3);

//Using 4th slot
    std::cout << "TEST==Using 4th slot : nothing should happen" << std::endl;
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->use(0, *susan);
    me->use(1, *susan);
    me->use(2, *susan);
    me->use(3, *susan);
    me->use(4, *susan);

    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->unequip(0);
    me->unequip(0);
    me->unequip(1);
    me->unequip(1);
    me->unequip(2);
    me->unequip(2);
    me->unequip(3);
    me->unequip(3);
    me->unequip(3);

    std::cout << "TEST==Using empty slot : nothing should happen" << std::endl;
    me->use(0, *susan);
    me->use(1, *susan);
    me->use(2, *susan);
    me->use(3, *susan);
    me->use(4, *susan);
    me->use(5, *susan);
    me->use(-1, *susan);
    me->use(-2, *susan);

    delete susan;
    std::cout << "ADDITIONAL TEST DONE" << std::endl;
//Done

    delete bob;
    delete me;
    delete src;

    Waste::waste_del_all();
    // system("leaks ex03 | grep leaked");
    // atexit(leaks_exit);
    return 0;
}
