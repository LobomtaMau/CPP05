#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n";
    try {
        Bureaucrat bob("Bob", 2);
        Form formA("FormA", 3, 5);

        std::cout << bob << "\n";
        std::cout << formA << "\n";
        std::cout << "\n";

        bob.signForm(formA);

        Bureaucrat alice("Alice", 5);
        Form formB("FormB", 4, 5);
        std::cout << "\n";

        std::cout << alice << "\n";
        std::cout << formB << "\n";

        alice.signForm(formB);
        std::cout << "\n";
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    std::cout << "\n";
    return 0;
}