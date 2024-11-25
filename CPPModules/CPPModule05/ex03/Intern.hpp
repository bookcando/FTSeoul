#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    private:
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
    
    public:
        Intern();
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif
