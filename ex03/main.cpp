#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(std::time(NULL)); // Initialize random seed

    try {
        // Create Bureaucrats
        Bureaucrat Toy("Toy", 50);
        Bureaucrat Maria("Maria", 1);
        Bureaucrat empata("empata", 150);

        std::cout << Toy << std::endl;
        std::cout << Maria << std::endl;
        std::cout << empata << "\n\n";

        // Create Forms
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Target");
        PresidentialPardonForm pardon("Criminal");
        std::cout << shrubbery << "\n";

        // Sign and execute ShrubberyCreationForm
        std::cout << shrubbery << std::endl;
        Toy.signForm(shrubbery);
        Toy.executeForm(shrubbery);
        std::cout << shrubbery << "\n\n";

        // Sign and execute RobotomyRequestForm
        std::cout << robotomy << std::endl;
        Toy.signForm(robotomy);
        Toy.executeForm(robotomy); // Toy can't execute
        Maria.executeForm(robotomy); // Maria can execute
        std::cout << robotomy << "\n\n";

        // Sign and execute PresidentialPardonForm
        std::cout << pardon << std::endl;
        Maria.signForm(pardon);
        Maria.executeForm(pardon);
        std::cout << pardon << "\n\n";

        // Attempt to sign form with a bureaucrat with too low grade
        empata.signForm(shrubbery);
        empata.executeForm(shrubbery);
        std::cout << pardon << "\n\n";
        
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
