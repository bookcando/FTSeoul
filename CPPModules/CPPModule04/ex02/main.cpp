#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

// void leak_test()
// {
//     system("leaks ex02 | grep leaked");
// }

int main(void)
{
    // atexit(leak_test);
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << "j->getType() : " << j->getType() << std::endl;
    std::cout << "i->getType() : " << i->getType() << std::endl;
    std::cout << std::endl;
    
    j->makeSound();
    i->makeSound();
    std::cout << std::endl;

    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_j = new WrongCat();
    std::cout << std::endl;

    std::cout << "wrong_j->getType() : " << wrong_j->getType() << std::endl;
    std::cout << std::endl;

    wrong_j->makeSound();
    std::cout << std::endl;



    std::cout << "copy test : memory leak test" << std::endl;
    Animal *cat_a = new Cat;
    Animal *cat_b = new Cat;
    Animal *dog_a = new Dog;
    Animal *dog_b = new Dog;
    std::cout << "copy test - objected generated" << std::endl;

    Animal *cat_copy = cat_a;
    *cat_a = *cat_copy;

    Animal *dog_copy = dog_a;
    *dog_a = *dog_copy;

    *dog_b = *dog_a;
    *cat_b = *cat_a;

    std::cout << "copy test - deleting objects..." << std::endl;
    delete dog_a;
    delete dog_b;
    delete cat_a;
    delete cat_b;
    std::cout << "copy test finished" << std::endl;
    // delete meta;
    delete j;
    delete i;
    delete wrong_meta;
    delete wrong_j;

    return (0);
}
