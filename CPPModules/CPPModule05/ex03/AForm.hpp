#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;
class AForm {
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signableGrade;
        const int           _executableGrade;
        AForm(); // can't create without arguments
        AForm &operator=(const AForm &copy); // can't change const-s

    public:
        AForm(const AForm &copy);
        virtual ~AForm();
        AForm(const std::string &name, int signableGrade, int executableGrade);

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

        // virtual void execute(Bureaucrat const &executor) const;
        void execute(Bureaucrat const &executor) const;
        virtual void executeAction() const = 0;

        class NotSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

};
std::ostream &operator<<(std::ostream &out, const AForm &Aform);
#endif