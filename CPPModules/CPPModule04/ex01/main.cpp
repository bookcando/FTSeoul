#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

// void leak_check()
// {
//     system("leaks ex01 | grep leaked");
// }

int main(void)
{
    // atexit(leak_check);
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << "j->getType() : " << j->getType() << std::endl;
    std::cout << "i->getType() : " << i->getType() << std::endl;
    std::cout << std::endl;
    
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_j = new WrongCat();
    std::cout << std::endl;

    std::cout << "wrong_j->getType() : " << wrong_j->getType() << std::endl;
    std::cout << std::endl;

    wrong_j->makeSound();
    std::cout << std::endl;

    std::cout << std::endl << std::endl;


    Animal *array[10];
    for (int i = 0; i < 5; ++i)
        array[i] = new Dog;
    for (int i = 5; i < 10; ++i)
        array[i] = new Cat;
    for (int i = 0; i < 10; ++i)
        delete array[i];
    
    



    delete meta;
    delete j;
    delete i;
    delete wrong_meta;
    delete wrong_j;
    std::cout << std::endl;
    return (0);
}
