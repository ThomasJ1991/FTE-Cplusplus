#ifndef FUNCTION1D_VARIABLE_HPP
#define FUNCTION1D_VARIABLE_HPP
#include "Function1dBase.hpp"

class Function1dVariable : public Function1dBase  {
public:
    double value(double x) const override;
    double derivative(double x) const override;
};

#endif //FUNCTION1D_VARIABLE_HPP
