#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    if (this == &other)
        return *this;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    AForm *newForm = NULL;
    
    if (formName == "shrubbery creation")
        newForm = createShrubberyCreationForm(target);
    else if (formName == "robotomy request")
        newForm = createRobotomyRequestForm(target);
    else if (formName == "presidential pardon")
        newForm = createPresidentialPardonForm(target);
    else
        std::cout << "Error: Form name '" << formName << "' not recognized." << std::endl;

    return newForm;
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const {
    return new PresidentialPardonForm(target);
}