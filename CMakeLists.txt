cmake_minimum_required(VERSION 3.10)

# Set your project name
project(FTE-Cplusplus)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library target
add_library(FTE-CplusplusLib src/Function.cpp)

# Specify the public include directory
target_include_directories(FTE-CplusplusLib PUBLIC include)

# Add the executable target (test or demo app)
add_executable(AutoDiffTestingApp test/main.cpp)

# Link the library with the executable
target_link_libraries(AutoDiffTestingApp FTE-CplusplusLib)
