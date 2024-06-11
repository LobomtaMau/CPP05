#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat Toy("Toy", 2);
        std::cout << Toy << std::endl;

        Toy.incrementGrade();
        std::cout << Toy << std::endl;

        Toy.incrementGrade();
        std::cout << Toy << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat tonixa("Tonixa", 149);
        std::cout << tonixa << std::endl;

        tonixa.decrementGrade();
        std::cout << tonixa << std::endl;

        tonixa.decrementGrade();
        std::cout << tonixa << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid("Invalid", 151); 
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid("Invalid", 0);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    return 0;
}
