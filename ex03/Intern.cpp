#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    if(this != &other)
        *this = other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    
}
