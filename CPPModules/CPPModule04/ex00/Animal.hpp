#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected :
        std::string type;
    
    public :
        Animal(); // Default constructor
        Animal(const Animal &copy); // Copy constructor
        Animal &operator=(const Animal &copy); // Copy assignment operator
        virtual ~Animal(); // Destructor
        
        void virtual makeSound() const;
        std::string getType() const;
};

#endif
