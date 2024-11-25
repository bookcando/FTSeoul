#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog(); // Default constructor
        Dog(const Dog &copy); // Copy constructor
        Dog &operator=(const Dog &copy); // Copy assignment operator
        ~Dog(); // Destructor

        void makeSound() const;
};

#endif
