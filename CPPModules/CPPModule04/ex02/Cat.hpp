#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain *brain;

    public :
        Cat(); // Default constructor
        Cat(const Cat &copy); // Copy constructor
        Cat &operator=(const Cat &copy); // Copy assignment operator
        virtual ~Cat(); // Destructor

        void makeSound() const;
};

#endif
