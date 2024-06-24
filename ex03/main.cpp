#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
        AForm *shrubbery = NULL;
        AForm *robotomy = NULL;
        AForm *pardon = NULL;

    try {
        Intern randomIntern;
        Bureaucrat boss("Boss", 1);

        shrubbery = randomIntern.makeForm("shrubbery creation", "Tree");
        robotomy = randomIntern.makeForm("robotomy request", "Bender");
        pardon = randomIntern.makeForm("presidential pardon", "Alice");

        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);

        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);

        boss.signForm(*pardon);
        boss.executeForm(*pardon);

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        
    }
    
    delete shrubbery;
    delete robotomy;
    delete pardon;

    return 0;
}

