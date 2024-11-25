#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy) {
        _grade = copy.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::promoteGrade() {
    if (_grade <= 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    --_grade;
}

void Bureaucrat::demoteGrade() {
    if (_grade >= 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    ++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat::GradeTooHighException : Bureaucrat Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat::GradeTooLowException : Bureaucrat Grade is too low";
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << _name\
        << " signed " << form.getName()\
        << "." << std::endl;
    }
    catch (AForm::GradeTooLowException &e) {
        std::cout << _name\
        << " couldn't sign " << form.getName()\
        << " because " << _name << "'s grade is too low."\
        << std::endl;
    }
    catch (AForm::AlreadySignedException &e) {
        std::cout << _name\
        << " couldn't sign " << form.getName()\
        << " because " << form.getName() << " is already signed."\
        << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) {
    try {
        form.execute(*this);
        std::cout << _name\
        << " executed " << form.getName()\
        << "." << std::endl;
    }
    catch (AForm::NotSignedException &e) {
        std::cout << _name\
        << " couldn't execute " << form.getName()\
        << " because " << form.getName() << " is not signed."\
        << std::endl;
    }
    catch (AForm::GradeTooLowException &e) {
        std::cout << _name\
        << " couldn't execute " << form.getName()\
        << " because " << _name << "'s grade is too low."\
        << std::endl;
    }
}
