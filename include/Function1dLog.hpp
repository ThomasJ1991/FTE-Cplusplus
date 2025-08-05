#ifndef FUNCTION1D_LOG_HPP
#define FUNCTION1D_LOG_HPP

#include <memory>
#include "Function1dBase.hpp"

class Function1dLog : public Function1dBase {
public:
    Function1dLog(const std::shared_ptr<Function1dBase>&  base):  function_base(base) {
    };
    double value(double x) const override;
    double derivative(double x) const override;

private:
    std::shared_ptr<Function1dBase> function_base;
    void validator(double x) const;
};


#endif //FUNCTION1D_LOG_HPP
