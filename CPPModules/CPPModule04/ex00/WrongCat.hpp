#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat(); // Default constructor
        WrongCat(const WrongCat &copy); // Copy constructor
        WrongCat &operator=(const WrongCat &copy); // Copy assignment operator
        ~WrongCat(); // Destructor

        void makeSound() const;
};

#endif
