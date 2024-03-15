cmake_minimum_required(VERSION 3.21)
project(Abstractions)

set(CMAKE_CXX_STANDARD 11)

# Specify the source files for your executable
set(SOURCES
        "2016 practice problems/problem2/StringManipulation.cpp" "2016 practice problems/problem2/StringManipulation.h" "2016 practice problems/main.cpp")

# Create the executable target with a valid name
add_executable(Abstractions ${SOURCES})
