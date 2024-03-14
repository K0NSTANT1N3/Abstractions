cmake_minimum_required(VERSION 3.21)
project(Abstractions)

set(CMAKE_CXX_STANDARD 11)

# Specify the source files for your executable
set(SOURCES
        "2016 practice problems/problem1/MinMaxMid.cpp"
        "2016 practice problems/problem1/MinMaxMid.h"
        "2016 practice problems/problem1/PowerOfTwo.cpp" "2016 practice problems/problem1/PowerOfTwo.h" "2016 practice problems/problem1/Euclide.cpp" "2016 practice problems/problem1/Euclide.h")

# Create the executable target with a valid name
add_executable(Abstractions ${SOURCES})
