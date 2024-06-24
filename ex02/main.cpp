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
        std::cout << empata << "\n";

        // Create Forms
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Target");
        PresidentialPardonForm pardon("Criminal");

        // Sign and execute ShrubberyCreationForm
        std::cout << "\nTEST SHUBE \n";
        std::cout << shrubbery << std::endl;
        Toy.executeForm(shrubbery);
        Toy.signForm(shrubbery);
        std::cout << shrubbery << "\n\n";

        // Sign and execute RobotomyRequestForm
        std::cout << "\nTEST ROBOT \n";
        std::cout << robotomy << std::endl;
        Toy.signForm(robotomy);
        Toy.executeForm(robotomy); // Toy can't execute
        Maria.executeForm(robotomy); // Maria can execute
        std::cout << robotomy << "\n\n";

        // Sign and execute PresidentialPardonForm
        std::cout << "\nTEST PARDON \n";
        std::cout << pardon << std::endl;
        Maria.signForm(pardon);
        Maria.executeForm(pardon);
        std::cout << pardon << "\n\n";

        // Attempt to sign form with a bureaucrat with too low grade
        std::cout << "\n TEST EMPATA \n";
        empata.signForm(shrubbery);
        empata.executeForm(shrubbery);
        std::cout << "\n\n";
        
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
