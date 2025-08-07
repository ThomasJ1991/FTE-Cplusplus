#ifndef FUNCTION1D_LOG_HPP
#define FUNCTION1D_LOG_HPP

#include <memory>
#include "Function1dBase.hpp"

class Function1dLog : public Function1dBase {
public:
    double value(double x) const override;
    double derivative(double x) const override;
private:
    void validator(double x) const;
};


#endif //FUNCTION1D_LOG_HPP
