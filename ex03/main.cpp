#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);

        std::cout << "AQUI 2\n";
        AForm *shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        std::cout << "AQUI 1\n";
        AForm *robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Alice");

        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);

        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);

        boss.signForm(*pardon);
        boss.executeForm(*pardon);

        delete shrubbery;
        delete robotomy;
        delete pardon;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
