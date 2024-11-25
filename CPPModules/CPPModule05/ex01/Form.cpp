#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _signableGrade(150), _executableGrade(150) {}

Form::Form(const Form &copy) : _name(copy.getName()), _signed(false), _signableGrade(copy.getSignableGrade()), _executableGrade(copy.getExecutableGrade()) {}

Form &Form::operator=(const Form &copy) {
    if (this != &copy) {
        _signed = copy.getSigned();
    }
    return *this;
}

Form::~Form() {}

Form::Form(const std::string &name, int signableGrade, int executableGrade) : _name(name), _signed(false), _signableGrade(signableGrade), _executableGrade(executableGrade) {
    if (signableGrade < 1 || executableGrade < 1) {
        throw Form::GradeTooHighException();
    } else if (signableGrade > 150 || executableGrade > 150) {
        throw Form::GradeTooLowException();
    }
}

std::string Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getSignableGrade() const {
    return _signableGrade;
}

int Form::getExecutableGrade() const {
    return _executableGrade;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form::GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form::GradeTooLowException";
}

const char *Form::AlreadySignedException::what() const throw() {
    return "Form::AlreadySignedException";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << form.getName()\
    << ", form signed ";
    //  << form.getSigned()
    if (form.getSigned()) {
        out << "true";
    } else {
        out << "false";
    }
    out << ", signable grade " << form.getSignableGrade()\
    << ", executable grade " << form.getExecutableGrade()\
    << ".";
    return out;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signableGrade) {
        throw Form::GradeTooLowException();
    } else if (_signed) {
        throw Form::AlreadySignedException();
    }
    _signed = true;
}