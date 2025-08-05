#ifndef FUNCTION1D_HELPERS_HPP
#define FUNCTION1D_HELPERS_HPP

#include <memory>
#include "Function1dBase.hpp"
#include "Function1dConstant.hpp"
#include "Function1dLog.hpp"
#include "Function1dPower.hpp"
#include "Function1dProduct.hpp"
#include "Function1dQuotient.hpp"
#include "Function1dVariable.hpp"
#include "Function1dSum.hpp"

namespace function1d {
    using function1d_ptr = std::shared_ptr<Function1dBase>;

    inline function1d_ptr Const(double u) {
        return std::make_shared<Function1dConstant>(u);
    }

    inline function1d_ptr Var() {
        return std::make_shared<Function1dVariable>();
    }

    inline function1d_ptr Log(const function1d_ptr& u) {
        return std::make_shared<Function1dLog>(u);
    }

    inline function1d_ptr Sum(const function1d_ptr& u, const function1d_ptr& v) {
        return std::make_shared<Function1dSum>(u, v);
    }
    inline function1d_ptr Power(const function1d_ptr& u, const function1d_ptr& v) {
        return std::make_shared<Function1dPower>(u, v);
    }

    inline function1d_ptr Product(const function1d_ptr& u, const function1d_ptr& v) {
        return std::make_shared<Function1dProduct>(u, v);
    }

    inline function1d_ptr Quotient(const function1d_ptr& u, const function1d_ptr& v) {
        return std::make_shared<Function1dQuotient>(u, v);
    }

}

#endif //FUNCTION1D_HELPERS_HPP
