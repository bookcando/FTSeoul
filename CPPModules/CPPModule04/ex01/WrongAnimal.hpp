#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected :
        std::string type;
    
    public :
        WrongAnimal(); // Default constructor
        WrongAnimal(const WrongAnimal &copy); // Copy constructor
        WrongAnimal &operator=(const WrongAnimal &copy); // Copy assignment operator
        virtual ~WrongAnimal(); // Destructor
        
        void makeSound() const; // not virtual makeSound.
        std::string getType() const;
};
// makeSound without virtual keyword will make it to called by the type of the pointer,
// not the exact type of the object.

#endif
