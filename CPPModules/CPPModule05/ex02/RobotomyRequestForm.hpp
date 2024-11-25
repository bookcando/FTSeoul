#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
        RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

    public:
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        std::string getTarget() const;
        virtual void executeAction() const;
};


#endif
