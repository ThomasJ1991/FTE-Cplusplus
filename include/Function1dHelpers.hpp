#ifndef FUNCTION1D_HELPERS_HPP
#define FUNCTION1D_HELPERS_HPP

#include <memory>
#include "Function1dBase.hpp"
#include "Function1dConstant.hpp"
#include "Function1dLog.hpp"
#include "Function1dPower.hpp"
#include "Function1dOperator.hpp"

namespace function1d {
    using function1d_ptr = std::shared_ptr<Function1dBase>;

    inline function1d_ptr Const(double u) {
        return std::make_shared<Function1dConstant>(u);
    }

    inline function1d_ptr Log() {
        return std::make_shared<Function1dLog>();
    }

    inline function1d_ptr Power(double power) {
        return std::make_shared<Function1dPower>(power);
    }


    inline function1d_ptr Add(const function1d_ptr& u, const function1d_ptr& v) {
        return std::make_shared<Function1dOperator>(u, v, Function1dOperator::Add);
    }

    inline function1d_ptr Subtract(const function1d_ptr& u, const function1d_ptr& v) {
        return std::make_shared<Function1dOperator>(u, v, Function1dOperator::Subtract);
    }

    inline function1d_ptr Composite(const function1d_ptr& u, const function1d_ptr& v) {
        return std::make_shared<Function1dOperator>(u, v, Function1dOperator::Composite);
    }

    inline function1d_ptr Multiply(const function1d_ptr& u, const function1d_ptr& v) {
        return std::make_shared<Function1dOperator>(u, v, Function1dOperator::Multiply);
    }
    inline function1d_ptr Divide(const function1d_ptr& u, const function1d_ptr& v) {
        return std::make_shared<Function1dOperator>(u, v, Function1dOperator::Divide);
    }
}

#endif //FUNCTION1D_HELPERS_HPP
