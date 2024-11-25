#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
class AForm;
class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;
        Bureaucrat(); // no grade
        Bureaucrat &operator=(const Bureaucrat &copy); // const name cannot be changed

    public:
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void promoteGrade();
        void demoteGrade();

        Bureaucrat(const std::string &name, int grade);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        void signForm(AForm &form);
        void executeForm(const AForm &form);
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
