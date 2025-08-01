#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>
#include <stdexcept>

class Function {
public:
    // Returns f(x), throws exception on invalid input
    double evaluate(double x) const;

    // Returns f'(x), throws exception on invalid input
    double derivative(double x) const;

    // Returns symbolic string
    std::string to_string() const;

private:
    // Returns g(x), throws exception on invalid input
    double g_evaluate(double x) const;

    // Returns g'(x), throws exception on invalid input
    double g_derivative(double x) const;

    // Validates the input variable
    void validate(double x) const;
};

#endif // FUNCTION_HPP
