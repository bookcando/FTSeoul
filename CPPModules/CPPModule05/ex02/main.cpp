#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    Bureaucrat worker1("worker1", 1);
    Bureaucrat worker2("worker2", 137);
    Bureaucrat worker3("worker3", 145);
    Bureaucrat worker4("worker4", 146);
    std::cout << "-----------------------------" << std::endl;
    std::cout << "worker1: " << worker1 << std::endl;
    std::cout << "worker2: " << worker2 << std::endl;
    std::cout << "worker3: " << worker3 << std::endl;
    std::cout << "worker4: " << worker4 << std::endl;
    std::cout << "-----------------------------" << std::endl;
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("home");
    PresidentialPardonForm pardon("home");

    std::cout << "-----------------------------" << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;
    std::cout << "-----------------------------" << std::endl;
    worker4.signForm(shrubbery);
    worker4.signForm(robotomy);
    worker4.signForm(pardon);
    std::cout << "-----------------------------" << std::endl;
    worker3.signForm(shrubbery);
    worker3.signForm(robotomy);
    worker3.signForm(pardon);
    std::cout << "-----------------------------" << std::endl;
    worker2.signForm(shrubbery);
    worker2.signForm(robotomy);
    worker2.signForm(pardon);
    std::cout << "-----------------------------" << std::endl;
    worker1.signForm(shrubbery);
    worker1.signForm(robotomy);
    worker1.signForm(pardon);
    std::cout << "-----------------------------" << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;
    std::cout << "-----------------------------" << std::endl;
    worker4.executeForm(shrubbery);
    worker4.executeForm(robotomy);
    worker4.executeForm(pardon);
    std::cout << "-----------------------------" << std::endl;
    worker3.executeForm(shrubbery);
    worker3.executeForm(robotomy);
    worker3.executeForm(pardon);
    std::cout << "-----------------------------" << std::endl;
    worker2.executeForm(shrubbery);
    worker2.executeForm(robotomy);
    worker2.executeForm(pardon);
    std::cout << "-----------------------------" << std::endl;
    worker1.executeForm(shrubbery);
    worker1.executeForm(robotomy);
    worker1.executeForm(robotomy);
    worker1.executeForm(robotomy);
    worker1.executeForm(robotomy);
    worker1.executeForm(pardon);
    
    return 0;
}