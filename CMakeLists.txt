cmake_minimum_required(VERSION 3.10)

project(FTE_Cplusplus VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files
file(GLOB SOURCES src/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)  # <--- This helps CLion indexer

add_executable(FTE_Cplusplus
        ${SOURCES}
        test/main.cpp
)

# THIS is what makes #include "Function1dBase.hpp" work
target_include_directories(FTE_Cplusplus PUBLIC ${PROJECT_SOURCE_DIR}/include)