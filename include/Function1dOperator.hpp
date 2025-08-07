#ifndef FUNCTION1D_OPERATOR_HPP
#define FUNCTION1D_OPERATOR_HPP
#include <memory>

#include "Function1dBase.hpp"

class Function1dOperator : public Function1dBase {
public:
    enum Type { Composite, Add, Subtract, Multiply, Divide };
    Function1dOperator(const std::shared_ptr<Function1dBase>& u, const std::shared_ptr<Function1dBase>& v, const Type t)
        : type(t), func_u(u), func_v(v) {}

    double value(double x) const override;
    double derivative(double x) const override;
 private:
    Type type;
    std::shared_ptr<Function1dBase> func_u; // for outer function of composite or left function in binary operations
    std::shared_ptr<Function1dBase> func_v; // for inner function of composite or right function in binary operations
};

#endif //FUNCTION1D_OPERATOR_HPP
