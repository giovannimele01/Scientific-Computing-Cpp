cmake_minimum_required(VERSION 3.26)
project(Challenge1_APC_2023)

set(CMAKE_CXX_STANDARD 11)

add_executable(Challenge1_APC_2023 main.cpp
        Point.cpp
        Point.h
        Monomial.cpp
        Monomial.h
        FunctionRn.cpp
        FunctionRn.h
        Adam.cpp
        Adam.h
        Test1.h
        Test2.h
        Test3.h)
