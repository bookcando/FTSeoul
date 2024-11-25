#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _signableGrade(150), _executableGrade(150) {}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _signed(false), _signableGrade(copy.getSignableGrade()), _executableGrade(copy.getExecutableGrade()) {}

AForm &AForm::operator=(const AForm &copy) {
    if (this != &copy) {
        _signed = copy.getSigned();
    }
    return *this;
}

AForm::~AForm() {}

AForm::AForm(const std::string &name, int signableGrade, int executableGrade) : _name(name), _signed(false), _signableGrade(signableGrade), _executableGrade(executableGrade) {
    if (signableGrade < 1 || executableGrade < 1) {
        throw AForm::GradeTooHighException();
    } else if (signableGrade > 150 || executableGrade > 150) {
        throw AForm::GradeTooLowException();
    }
}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getSignableGrade() const {
    return _signableGrade;
}

int AForm::getExecutableGrade() const {
    return _executableGrade;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm::GradeTooHighException";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm::GradeTooLowException";
}

const char *AForm::AlreadySignedException::what() const throw() {
    return "AForm::AlreadySignedException";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
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

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signableGrade) {
        throw AForm::GradeTooLowException();
    } else if (_signed) {
        throw AForm::AlreadySignedException();
    }
    _signed = true;
}

const char *AForm::NotSignedException::what() const throw() {
    return "AForm::NotSignedException";
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!_signed) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > _executableGrade) {
        throw AForm::GradeTooLowException();
    }
    executeAction();
}

