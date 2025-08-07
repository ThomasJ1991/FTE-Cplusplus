#include <Function1dOperator.hpp>

double Function1dOperator::value(double x) const {
    switch (type) {
        case Composite: {
            double inner_val = func_v->value(x);
            return func_u->value(inner_val);
        }
        case Add:
            return func_u->value(x) + func_v->value(x);
        case Subtract:
            return func_u->value(x) - func_v->value(x);
        case Multiply:
            return func_u->value(x) * func_v->value(x);
        case Divide:
            return func_u->value(x) / func_v->value(x);
    }
    return 0; // should never reach here
}

double Function1dOperator::derivative(double x) const {
    switch (type) {
        case Composite: {
            //u(v(x))
            double v = func_v->value(x);
            //u'(v(x))
            double du_v = func_u->derivative(v);
            double dv = func_v->derivative(x);
            return du_v * dv;
        }
        case Add:
            return func_u->derivative(x) + func_v->derivative(x);
        case Subtract:
            return func_u->derivative(x) - func_v->derivative(x);
        case Multiply:
            //u(x)*v(x)
            return func_u->derivative(x) * func_v->value(x) + func_u->value(x) * func_v->derivative(x);
        case Divide: {
            //u(x)/v(x)
            double u = func_u->value(x), v = func_v->value(x);
            double du = func_u->derivative(x), dv = func_v->derivative(x);
            return (du * v - u * dv) / (v * v);
        }
    }
    return 0;
}