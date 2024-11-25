#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat(); // Default constructor
        Cat(const Cat &copy); // Copy constructor
        Cat &operator=(const Cat &copy); // Copy assignment operator
        ~Cat(); // Destructor

        void makeSound() const;
};

#endif
