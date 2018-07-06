cmake_minimum_required(VERSION 3.10)
project(multithreaded_matrix)

set(CMAKE_CXX_STANDARD 11)
SET(GCC_COVERAGE_LINK_FLAGS    "-pthread ")
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

add_executable(tests      tests.cpp      matrix.h matrix.cpp)
add_executable(benchmarks benchmarks.cpp matrix.h matrix.cpp)