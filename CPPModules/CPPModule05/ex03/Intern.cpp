#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) {
    if (this != &copy) {
        *this = copy;
    }
}

Intern &Intern::operator=(const Intern &copy) {
    if (this != &copy) {
        *this = copy;
    }
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {

    struct FormMapping {
        std::string name;
        AForm *(*formCreator)(const std::string &);
    };

    FormMapping formMappings[] = {
        {"shrubbery creation", &ShrubberyCreationForm::create},
        {"robotomy request", &RobotomyRequestForm::create},
        {"presidential pardon", &PresidentialPardonForm::create},
        {"", 0}
    };

    for (int i = 0; formMappings[i].name != ""; ++i) {
        if (formName == formMappings[i].name) {
            std::cout << "Intern creates " << formName << "." << std::endl;
            return formMappings[i].formCreator(target);
        }
    }

    std::cout << "Intern couldn't create form " << formName << ". form does not exist." << std::endl;
    return 0;
}
