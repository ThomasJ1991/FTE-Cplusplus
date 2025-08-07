#include <valarray>
#include "Function1dPower.hpp"

double Function1dPower::value(double x) const {
    validator(x);
    return std::pow(x, power_);
}

double Function1dPower::derivative(double x) const {
    validator(x);
    return power_ * std::pow(x, power_ - 1.0);
}

void Function1dPower::validator(double x) const {
    if (abs(x) == 0.0 && power_ < 0.0)
        throw std::invalid_argument("Power function x^n is undefined at x = 0 when x<0");

    if (x < 0.0 && abs(power_) < 1.0)
        throw std::invalid_argument("Power function x^n is not producing real number when x < 0 and n is fraction");
}