#include <iostream>
#include <valarray>

#include "Function1dPower.hpp"

double Function1dPower::value(double x) const {
    validator(x);
    return std::pow(function_base->value(x), function_power->value(x));
}

double Function1dPower::derivative(double x) const {
    validator(x);
    return value(x) * (function_power->derivative(x) * std::log(abs(function_base->value(x))) +
                      function_power->value(x) * function_base->derivative(x)/ function_base->value(x));
}

void Function1dPower::validator(double x) const {
    double base = function_base->value(x);
    double power = function_power->value(x);
    // std::cout << "power function base argument at x = " << x << " is " << base << std::endl;
    // std::cout << "power function power argument at x = " << x << " is " << power << std::endl;
    if ((abs(power) < 1 &&  base <= 0)|| (base == 0.0 && power < 0))
        throw std::invalid_argument("Power function are not producing real numbers");
}