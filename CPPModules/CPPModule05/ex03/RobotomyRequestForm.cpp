#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

#include <ctime>
#include <cstdlib>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default") {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy) {
        _target = copy._target;
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::executeAction() const {
    // std::srand(std::time(0));
    struct timeval time;
    gettimeofday(&time, NULL);
    srand(time.tv_usec * time.tv_sec);

    std::cout << "*Ddddddrilling noise...*" << std::endl;
    if (rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << _target << " robotomization has failed" << std::endl;
    }
}


AForm *RobotomyRequestForm::create(const std::string &target) {
    return new RobotomyRequestForm(target);
}
