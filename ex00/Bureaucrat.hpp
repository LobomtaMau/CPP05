#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
    private:
        std::string _name;
        int _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(std::string &other);
        Bureaucrat &operator=(Bureaucrat &other);
        ~Bureaucrat();

        Bureaucrat::GradeTooHighException;
        Bureaucrat::GradeTooLowException;
        
};


#endif