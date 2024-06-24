#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:
        AForm* createShrubberyCreationForm(const std::string& target) const;
        AForm* createRobotomyRequestForm(const std::string& target) const;
        AForm* createPresidentialPardonForm(const std::string& target) const;
        
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target) const;
        
        class InvlaidFileException : public std::exception {
            public:
                const char *what() const throw(){
                    return "Uknown Form Type!";
                }
        };    
};

#endif