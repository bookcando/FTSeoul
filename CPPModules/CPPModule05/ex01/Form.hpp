#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;
class Form {
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signableGrade;
        const int           _executableGrade;
        Form(); // can't create without arguments
        Form &operator=(const Form &copy); // can't change const-s

    public:
        Form(const Form &copy);
        ~Form();
        Form(const std::string &name, int signableGrade, int executableGrade);

        std::string getName() const;
        bool getSigned() const;
        int getSignableGrade() const;
        int getExecutableGrade() const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class AlreadySignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &out, const Form &form);
#endif