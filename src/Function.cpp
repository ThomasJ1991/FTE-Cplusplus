#include "Function.hpp"
#include <cmath>

// Define the inner function g(x) = (x^2-5)*(4-3*x)
double Function::g_evaluate(double x) const{
    return (x * x - 5.0) * (4.0 - 3.0 * x);  
}

// Define the derivative of g(x), g'(x) = -9x^2+8*x+15
double Function::g_derivative(double x) const{
    return -9.0 * x * x + 8 * x + 15.0;
}

// Define the target function f(x) = 5 + x^3 - ln(g(x))/(x-4)
double Function::evaluate(double x) const {
    double x3 = x * x * x;
    double g = g_evaluate(x);

    if (g <= 0) {
        throw std::domain_error("ln(g(x)) domain error: (x^2 - 5)(4 - 3x) <= 0");
    }
    if (x == 4.0) {
        throw std::domain_error("Division by zero: x - 4 == 0");
    }

    double ln_g = std::log(g);
    double denom = x - 4.0;

    return 5.0 + x3 - ln_g / denom;
}

// Define the derivative of target function f'(x)
double Function::derivative(double x) const {
    double x2 = x * x;
    double g =  g_evaluate(x);

  
    if (g <= 0) {
        throw std::domain_error("ln(g(x)) domain error: (x^2 - 5)(4 - 3x) <= 0");
    }
    if (x == 4.0) {
        throw std::domain_error("Division by zero: x - 4 == 0");
    }

    double dg = g_derivative(x);
    double ln_g = std::log(g);
    double denom = x - 4.0;
    double latter_part = (dg / g) / denom - ln_g / (denom * denom);

    return 3.0 * x2 - latter_part;
}

std::string Function::to_string() const {
    return "f(x) = 5 + x^3 - ln((x^2 - 5)(4 - 3x)) / (x - 4)";
}
