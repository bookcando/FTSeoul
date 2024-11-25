#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
        ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

    public:
        static AForm *create(const std::string &target);

        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        std::string getTarget() const;
        virtual void executeAction() const;
};

#endif
