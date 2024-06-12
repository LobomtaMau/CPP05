#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target) const;
    
private:
    AForm *createShrubberyCreationForm(const std::string &target) const;
    AForm *createRobotomyRequestForm(const std::string &target) const;
    AForm *createPresidentialPardonForm(const std::string &target) const;
};

#endif