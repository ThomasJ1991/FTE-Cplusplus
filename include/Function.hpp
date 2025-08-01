#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>
#include <stdexcept>

class Function {
public:
    // Returns g(x), throws exception on invalid input
    double g_evaluate(double x) const;

    // Returns g'(x), throws exception on invalid input
    double g_derivative(double x) const;

    // Returns f(x), throws exception on invalid input
    double f_evaluate(double x) const;

    // Returns f'(x), throws exception on invalid input
    double f_derivative(double x) const;

    // Returns symbolic string
    std::string to_string() const;
};

#endif // FUNCTION_HPP
