#ifndef FUNCTION1D_QUOTIENT_HPP
#define FUNCTION1D_QUOTIENT_HPP

#include <memory>
#include "Function1dBase.hpp"

class Function1dQuotient : public Function1dBase {
public:
    Function1dQuotient(const std::shared_ptr<Function1dBase>& num, const std::shared_ptr<Function1dBase>& denom):  function_numerator(num), function_denominator(denom) {
    };
    double value(double x) const override;
    double derivative(double x) const override;
private:
    std::shared_ptr<Function1dBase> function_numerator;
    std::shared_ptr<Function1dBase> function_denominator;
    void validator(double x) const;
};


#endif //FUNCTION1D_QUOTIENT_HPP
