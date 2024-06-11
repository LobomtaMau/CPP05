#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

        void checkGrade(int grade) const;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(Bureaucrat &other);
        virtual ~Bureaucrat();


        class GradeTooHighException : public std::runtime_error {
            public:
                GradeTooHighException() : std::runtime_error("Grade is to high!") {}
        };

        class GradeTooLowException : public std::runtime_error {
            public:
                GradeTooLowException() : std::runtime_error("grade is to low!") {}
        };

        
        const std::string &getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(Form &form);
        
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif