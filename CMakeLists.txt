cmake_minimum_required(VERSION 3.10)
project(Abstractions)

# Include the directory containing header files
include_directories(${CMAKE_SOURCE_DIR}/lib/StanfordCPPLib)

# Add the executable target
add_executable(Abstractions

        src/tmp/OurLexicon.cpp src/tmp/OurLexicon.h src/2016-practice-problems/20/LLString.cpp src/2016-practice-problems/20/LLString.h)


# Link the executable target with the library target
target_link_libraries(Abstractions ${CMAKE_SOURCE_DIR}/lib/StanfordCPPLib/libStanfordCPPLib.a)

# Set the C++ standard to C++11
set_property(TARGET Abstractions PROPERTY CXX_STANDARD 11)

# Set the output directory for the executable
set_target_properties(Abstractions PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Set the output directory for the project
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Abstractions)

# Set the working directory for the project
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Find and link against necessary libraries
find_package(Threads REQUIRED)
target_link_libraries(Abstractions Threads::Threads)
