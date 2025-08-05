#ifndef FUNCTION1D_PRODUCT_HPP
#define FUNCTION1D_PRODUCT_HPP

#include <memory>
#include "Function1dBase.hpp"

class Function1dProduct : public Function1dBase {
public:
    Function1dProduct(const std::shared_ptr<Function1dBase>& u, const std::shared_ptr<Function1dBase>& v):  function_u(u), function_v(v) {
    };

    double value(double x) const override;
    double derivative(double x) const override;

private:
    std::shared_ptr<Function1dBase> function_u;
    std::shared_ptr<Function1dBase> function_v;
};


#endif //FUNCTION1D_PRODUCT_HPP
