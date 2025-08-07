#ifndef FUNCTION1D_POWER_HPP
#define FUNCTION1D_POWER_HPP

#include "Function1dBase.hpp"

class Function1dPower : public Function1dBase {
public:
    Function1dPower(double power = 1.0): power_(power){
    };
    double value(double x) const override;
    double derivative(double x) const override;
private:
    void validator(double x) const;
    double power_;
};


#endif //FUNCTION1D_POWER_HPP
