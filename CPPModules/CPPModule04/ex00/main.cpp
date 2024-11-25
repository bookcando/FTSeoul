#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
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

    delete meta;
    delete j;
    delete i;
    delete wrong_meta;
    delete wrong_j;

    return (0);
}
