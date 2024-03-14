cmake_minimum_required(VERSION 3.21)
project(Abstractions)

set(CMAKE_CXX_STANDARD 11)

# Specify the source files for your executable
set(SOURCES
        slides/01/Recursion.cpp
        slides/01/Recursion.h slides/main.cpp)

# Create the executable target with a valid name
add_executable(Abstractions ${SOURCES})
