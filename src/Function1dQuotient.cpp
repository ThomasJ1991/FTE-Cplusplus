#include <iostream>
#include "Function1dQuotient.hpp"
#include <valarray>

double Function1dQuotient::value(double x) const {
    validator(x);
    return function_numerator->value(x) / function_denominator->value(x);
}

double Function1dQuotient::derivative(double x) const {
    validator(x);
    return (function_numerator->derivative(x) * function_denominator->value(x) - function_numerator->value(x) * function_denominator->derivative(x)) /
            std::pow(function_denominator->value(x), 2.0);
}

void Function1dQuotient::validator(double x) const {
    double denom = function_denominator->value(x);
    // std::cout << "quotient denominator value argument at x = " << x << " is " << denom << std::endl;
    if (denom == 0.0)
        throw std::invalid_argument("Function quotient denominator must not be zero.");
}