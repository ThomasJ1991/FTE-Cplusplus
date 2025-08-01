#include <iostream>
#include <cctype>
#include "Function.hpp"

int main() {
    Function f;
    double x;
    char choice;
    
    std::cout << f.to_string() << "\n";
    std::cout << "Enter x: ";
    std::cin >> x;

    do {
        std::cout << "\nEnter a value for x: ";
        std::cin >> x;

        try {
            double fx = f.evaluate(x);
            double dfx = f.derivative(x);
            std::cout << "f(" << x << ") = " << fx << "\n";
            std::cout << "f'(" << x << ") = " << dfx << "\n";
        } catch (const std::domain_error& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }

        std::cout << "\nContinue with a new input x? (y/n): ";
        std::cin >> choice;

    } while (toppper(choice) == 'Y');

    std::cout << "End of the function\n";
    return 0;
}
