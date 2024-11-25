#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private :
        Brain *brain;

    public :
        Dog(); // Default constructor
        Dog(const Dog &copy); // Copy constructor
        Dog &operator=(const Dog &copy); // Copy assignment operator
        virtual ~Dog(); // Destructor

        void makeSound() const;
};

#endif
