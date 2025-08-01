#include "Function.hpp"
#include <cmath>

constexpr double UPPER_BOUND = std::sqrt(5.0);
constexpr double LOWER_BOUND = 4.0 / 3.0;


void Function::validate(double x) const {
    // Explicit variable range: x < -sqrt(5) or (4/3 < x < sqrt(5))
    if (!((x < -UPPER_BOUND) || (x > LOWER_BOUND && x < UPPER_BOUND))) {
        std::ostringstream oss;
        oss << "Input x = " << x << " is outside the valid boundary: "
            << "x < -√5 or (4/3 < x < √5)";
        throw std::domain_error(oss.str());
    }
}

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
    validate(x);
    double x3 = x * x * x;
    double g = g_evaluate(x);
    double ln_g = std::log(g);
    double denom = x - 4.0;

    return 5.0 + x3 - ln_g / denom;
}

// Define the derivative of target function f'(x)
double Function::derivative(double x) const {
    validate(x);
    double x2 = x * x;
    double g =  g_evaluate(x);
    double dg = g_derivative(x);
    double ln_g = std::log(g);
    double denom = x - 4.0;
    double latter_part = (dg / g) / denom - ln_g / (denom * denom);

    return 3.0 * x2 - latter_part;
}

std::string Function::to_string() const {
    return "f(x) = 5 + x^3 - ln((x^2 - 5)(4 - 3x)) / (x - 4)";
}
