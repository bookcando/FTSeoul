#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private :
        std::string ideas[100];
    
    public :
        Brain(); // Default constructor
        Brain(const Brain &copy); // Copy constructor
        Brain &operator=(const Brain &copy); // Copy assignment operator
        ~Brain(); // Destructor
};

#endif
