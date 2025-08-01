// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath> // For std::pow and other math functions

// Define the inner function g(x) = (x^2-5)*(4-3*x)
double g(double x) {
    return (pow(x,2.0) - 5.0) * (4.0-3.0*x);
}

// Define the derivative of g(x), g'(x) = -9x^2+8*x+15
double g_prime(double x) {
    return -9.0*pow(x,2.0)+8*x+15.0;
}

// Define the first component of outer function A(x) = 5+x^3
double A(double x) {
    return 5.0+pow(x,3.0);
}

// Define the derivative of first component A'(x)=3*x^2
double A_prime(double x) {
    return 3.0*pow(x,2.0);
}

// Define the second component of outer function B(x) = ln(g(x))/(x-4)
double B(double x) {
    //Need to check if g(x) is greater than 0
    if(g(x)>0 && x!=4.0) 
        return log(g(x))/(x-4.0);
    else
        throw std::invalid_argument("Input value has to satisfy the condition x<-sqrt(5) or 4/3<x<sqrt(5).");
}

// Define the derivative of second component of outer function B'(x) = g'(x)/(g(x)*(x-4))-ln(g(x))/((x-4)^2)
double B_prime(double x) {
    //Need to check if g(x) is greater than 0
    if(g(x)>0 && x!=4.0)
        return g_prime(x)/(g(x)*(x-4.0))-log(g(x))/(pow(x-4.0,2.0));
    else
        throw std::invalid_argument("Input value has to satisfy the condition x<-sqrt(5) or 4/3<x<sqrt(5).");
}
// Define the outer function f(x) = A(x)-B(x)
double f(double x) {
    return A(x)-B(x);
}

// Define the derivative of f(x), f'(x) = A'(x)-B'(x)
double f_prime(double x) {
    return A_prime(x) - B_prime(x);
}

int main() {
    double x0 = 4.0; // The point at which to evaluate the derivative

    // Calculate the function value at x0
    double value_at_x = f(x0);
    // Calculate the derivative using the chain rule
    double derivative_at_x = f_prime(x0);
    std::cout << "The function value at x = " << x0 << " is: " << value_at_x << std::endl;
    std::cout << "The derivative at x = " << x0 << " is: " << derivative_at_x << std::endl;
    return 0;
}

