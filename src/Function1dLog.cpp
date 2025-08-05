#include <iostream>
#include <valarray>

#include "Function1dLog.hpp"


double Function1dLog::value(double x) const {
    validator(x);
    return std::log(function_base->value(x));
}
double Function1dLog::derivative(double x) const {
    validator(x);
    return function_base->derivative(x) / function_base->value(x);
}

void Function1dLog::validator(double x) const {
    double val= function_base->value(x);
    // std::cout << "Log argument at x = " << x << " is " << val << std::endl;
    if (val<= 0.0 )
        throw std::invalid_argument("Function arguments must be positive.");
}