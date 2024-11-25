#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default") {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy) {
        _target = copy._target;
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream file;
    try {
        std::string filename = _target + "_shrubbery";

        file.open(filename.c_str());
        file << "         * " << std::endl;
        file << "        /|\\ " << std::endl;
        file << "       /*|O\\ " << std::endl;
        file << "      /*/|\\*\\ " << std::endl;
        file << "     /X/O|*\\X\\ " << std::endl;
        file << "    /*/X/|\\X\\*\\ " << std::endl;
        file << "   /O/*/X|*\\O\\X\\  *" << std::endl;
        file << "  /*/O/X/|\\X\\O\\*\\/|\\" << std::endl;
        file << " /X/O/*/X|O\\X\\*\\O\\|*\\ " << std::endl;
        file << "/O/X/*/O/|\\X\\*\\O\\X\\\\X\\ " << std::endl;
        file << "        |X|   /X/O|X\\O\\" << std::endl;
        file << "        |X|       |" << std::endl;

        file << std::endl;
        file.close();
    }
    catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
    }
}

AForm *ShrubberyCreationForm::create(const std::string &target) {
    return new ShrubberyCreationForm(target);
}
