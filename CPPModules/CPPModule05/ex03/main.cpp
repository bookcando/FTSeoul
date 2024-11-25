#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// void leakTest() {
//     system("leaks ex03 | grep leaked");
// }

int main(void) {
    // atexit(leakTest);
    
    Intern disposableIntern;
    AForm *form1 = disposableIntern.makeForm("shrubbery creation", "home");
    AForm *form2 = disposableIntern.makeForm("robotomy request", "home");
    AForm *form3 = disposableIntern.makeForm("presidential pardon", "home");
    AForm *form4 = disposableIntern.makeForm("blahblah form", "home");
    AForm *form5 = disposableIntern.makeForm("hihello form", "home");

    std::cout << "-----------------------------" << std::endl;
    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;
    std::cout << form4 << std::endl;
    std::cout << form5 << std::endl;

    std::cout << "-----------------------------" << std::endl;
    Bureaucrat worker1("worker1", 1);

    worker1.signForm(*form1);
    worker1.signForm(*form2);
    worker1.signForm(*form3);

    std::cout << "-----------------------------" << std::endl;
    worker1.executeForm(*form1);
    worker1.executeForm(*form2);
    worker1.executeForm(*form3);

    delete form1;
    delete form2;
    delete form3;
    delete form4; // deleting NULL -> no effect
    delete form5; // deleting NULL -> no effect

}