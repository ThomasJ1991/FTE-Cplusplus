#ifndef FUNCTION1D_POWER_HPP
#define FUNCTION1D_POWER_HPP

#include <memory>
#include "Function1dBase.hpp"

class Function1dPower : public Function1dBase {
public:
    Function1dPower(const std::shared_ptr<Function1dBase>& base, const std::shared_ptr<Function1dBase>& power):  function_base(base), function_power(power) {
    };
    double value(double x) const override;
    double derivative(double x) const override;
private:
    std::shared_ptr<Function1dBase> function_base;
    std::shared_ptr<Function1dBase> function_power;
    void validator(double x) const;
};


#endif //FUNCTION1D_POWER_HPP
