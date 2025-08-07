#include <valarray>
#include "Function1dLog.hpp"

double Function1dLog::value(double x) const {
    validator(x);
    return std::log(x);
}
double Function1dLog::derivative(double x) const {
    validator(x);
    return 1.0 / x;
}

void Function1dLog::validator(double x) const {
    if (x<= 0.0 )
        throw std::invalid_argument("Log Function arguments must be positive.");
}