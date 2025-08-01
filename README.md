# FTE-Cplusplus

# Goal
This project is designed to evaluate the value and the first order derivative of the following function given a real number that falls into the valid range.
f(x)=5+x^3-ln(g(x))/(x-4)
g(x)=(x^2-5)*(4-3x)

# Range
Based on the restriction of g(x) within ln, and denominator is x -4, then x can only fall in to the range of (-infinity,-5^0.5) or (4/3,5^0.5)

#How to compile

1.Copy the repo to a local folder called and create a subfolder build.
cd Testing
mkdir build
cd build
2.Run the following cmake command in the subdir
cmake ..
make
3. A executable will be generated as ./FTE-Cplusplus//build/AutoDiffTestingApp


# Example

./FTE-Cplusplus/build/AutoDiffTestingApp ; exit;
f(x) = 5 + x^3 - ln((x^2 - 5)(4 - 3x)) / (x - 4)
Enter x: 1.9
The function value f(1.9) = 12.2685
The derivative of the function f'(1.9) = 10.5635
