#include <iostream>

#include "Function1dBase.hpp"
#include "Function1dHelpers.hpp"

int main() {
    using namespace function1d;
    double input_variable;
    char choice;
    do {
        std::cout << "\nEnter a value for x: ";
        std::cin >> input_variable;

        try {
            function1d_ptr x = Var();
            function1d_ptr x_power_2 = Power(x,Const(2.0));
            function1d_ptr x_power_3 = Power(x,Const(3.0)) ;
            //g(x)=(x^2-5)*(4-3x)
            function1d_ptr g = Product(Sum(x_power_2,Const(-5.0)), Sum(Const(4.0),Product(x,Const(-3.0))));
            double gx= g->value(input_variable);
            std::cout << "g(" << input_variable << ") = " << gx << "\n";
            //ln(g(x))/(x-4)
            function1d_ptr quotient_g = Quotient(Log(g), Sum(x, Const(-4.0)));
            double quotient= quotient_g->value(input_variable);
            std::cout << "ln(g(" << input_variable << "))/(" << input_variable << "-4) = " << quotient << "\n";

            //f(x)=5+x^3-ln(g(x))/(x-4)
            function1d_ptr f = Sum(Sum(Const(5.0),x_power_3), Product(quotient_g,Const(-1.0)));
            double fx = f->value(input_variable);
            double dfx = f->derivative(input_variable);
            std::cout << "f(" << input_variable << ") = " << fx << "\n";
            std::cout << "f'(" << input_variable << ") = " << dfx << "\n";
        } catch (const std::invalid_argument& e) {
            std::cerr << "Math Error: " << e.what() << "\n";
        }

        std::cout << "\nContinue with a new input x? (y/n): ";
        std::cin >> choice;

    } while (toupper(choice) == 'Y');

    std::cout << "End of the function\n";
    return 0;
}