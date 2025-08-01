#include <iostream>
#include "Function.hpp"

int main() {
    Function f;
    double x;

    std::cout << f.to_string() << "\n";
    std::cout << "Enter x: ";
    std::cin >> x;

    try {
        double fx = f.evaluate(x);
        double dfx = f.derivative(x);
        std::cout << "The function value f(" << x << ") = " << fx << "\n";
        std::cout << "The derivative of the function f'(" << x << ") = " << dfx << "\n";
    } catch (const std::domain_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
