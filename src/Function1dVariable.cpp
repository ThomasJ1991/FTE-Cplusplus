#include "Function1dVariable.hpp"

double Function1dVariable::value(double x) const {
    return x;
}
double Function1dVariable::derivative(double x) const {
    return 1.0;
}
