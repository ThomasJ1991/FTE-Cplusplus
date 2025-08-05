#include "Function1dConstant.hpp"

double Function1dConstant::value(double x) const {
    return input_variable;
}
double Function1dConstant::derivative(double x) const {
    return 0.0;
}
