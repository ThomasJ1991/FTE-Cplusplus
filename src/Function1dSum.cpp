#include "Function1dSum.hpp"

double Function1dSum::value(double x) const {
    return function_u->value(x) + function_v->value(x);
}

double Function1dSum::derivative(double x) const {
    return function_u->derivative(x) + function_v->derivative(x);
}
