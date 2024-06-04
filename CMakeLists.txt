cmake_minimum_required(VERSION 3.15)
project(BigInt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(include)

option(BUILD_EXAMPLES "Build example files" ON)
option(BUILD_TESTS "Build test files" ON)

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()