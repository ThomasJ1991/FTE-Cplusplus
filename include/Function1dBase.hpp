#ifndef FUNCTION1D_BASE_HPP
#define FUNCTION1D_BASE_HPP

class Function1dBase {
public:
    virtual double value(double x) const = 0;
    virtual double derivative(double x) const = 0;
    virtual ~Function1dBase() = default;
};



#endif //FUNCTION1D_BASE_HPP
