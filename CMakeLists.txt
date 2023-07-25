# CMakeLists.txt in the root of your project

cmake_minimum_required(VERSION 3.5)
project(Grind75)

# Add the test source files using GLOB_RECURSE
file(GLOB_RECURSE SOURCES src/*.cpp test/*.cpp src/*.hpp)

# Create the executable target for your main application
add_executable(Grind75Solutions ${SOURCES})

# Add the subdirectory for the Catch2 tests
add_subdirectory(tests)
