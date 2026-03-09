cmake_minimum_required(VERSION 3.26)
project(Assignment3_initial)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment3_initial
        dense_matrix.cpp
        dense_matrix.hpp
        main.cpp
        matrix_assemble.cpp
        matrix_assemble.hpp
        matrix_diff.cpp
        matrix_diff.hpp
        matrix_split.cpp
        matrix_split.hpp)
