#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
        PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

    public:
        static AForm *create(const std::string &target);

        PresidentialPardonForm(const PresidentialPardonForm &copy);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        std::string getTarget() const;
        virtual void executeAction() const;
};

#endif
