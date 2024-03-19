cmake_minimum_required(VERSION 3.21)
project(Abstractions)

set(CMAKE_CXX_STANDARD 11)

# Include directory for cslib headers
include_directories(cpplib/include)

# Link against the cslib library
link_directories(cpplib/lib)  # Specify the directory containing the cslib library

# Specify the source files for your executable
set(SOURCES
        slides/main.cpp
        slides/03/TheShuntingYardAlgorithm.cpp
        slides/03/TheShuntingYardAlgorithm.h
        additional/recursion/Arithmetics.cpp
        additional/recursion/Arithmetics.h
        2016-practice-problems/02/StringManipulation.cpp
        2016-practice-problems/02/StringManipulation.h
        )

# Create the executable target with a valid name
add_executable(Abstractions ${SOURCES})
