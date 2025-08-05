#ifndef FUNCTION1D_CONSTANT_HPP
#define FUNCTION1D_CONSTANT_HPP
#include "Function1dBase.hpp"

class Function1dConstant : public Function1dBase  {
    double input_variable;
public:
    Function1dConstant(double x): input_variable(x) {}
    double value(double x) const override;
    double derivative(double x) const override;
};

#endif //FUNCTION1D_CONSTANT_HPP
