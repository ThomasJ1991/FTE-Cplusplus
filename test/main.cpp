#include <iostream>

#include "Function1dHelpers.hpp"


int main() {
    using namespace function1d;
    double x;
    char choice;
    bool validInput = false;
    do {
        while (!validInput) {
            std::cout << "\nEnter a value for x: ";
            std::cin >> x;
            if (std::cin.good()) {
                validInput = true; // Input was a valid double
            } else {
                std::cout << "Invalid input. Please enter a numerical value." << std::endl;
                std::cin.clear(); // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
        }

        try {

            auto x_power_2 = Power(2.0);
            auto x_power_3 = Power(3.0);
            auto const_5 = std::make_shared<Function1dConstant>(5.0);

            //g(x)=(x^2-5)*(4-3x)
            auto g = Multiply(Subtract(Power(2.0), Const(5.0)),
                                            Subtract(Const(4.0), Multiply(Const(3.0), Power(1.0))));
            double g_x = g->value(x);
            std::cout << "g(" << x << ") = " << g_x << "\n";

            //ln(g(x))/(x-4)
            auto quotient_g = Divide(Composite(Log(),g), Subtract(Power(1.0), Const(4.0)));
            double quotient_g_x = quotient_g->value(x);
            std::cout << "ln(g(" << x << "))/(" << x << "- 4) = " << quotient_g_x << "\n";

            //f(x)=5+x^3-ln(g(x))/(x-4)
            auto f = Subtract(Add(Const(5.0),Power(3.0)), quotient_g);
            double f_x = f->value(x);
            double df_x = f->derivative(x);
            std::cout << "f(" << x << ") = " << f_x << "\n";
            std::cout << "f'(" << x << ") = " << df_x << "\n";
        } catch (const std::invalid_argument& e) {
            std::cerr << "Math Error: " << e.what() << "\n";
        }

        std::cout << "\nContinue with a new input x? (y/n): ";
        std::cin >> choice;

    } while (toupper(choice) == 'Y');

    std::cout << "End of the function\n";
    return 0;
}