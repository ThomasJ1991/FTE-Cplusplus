#include "Function1dProduct.hpp"
#include <valarray>

double Function1dProduct::value(double x) const {
    return function_u->value(x) * function_v->value(x);
}

double Function1dProduct::derivative(double x) const {
    return function_u->derivative(x) * function_v->value(x) + function_u->value(x) * function_v->derivative(x);
}
