cmake_minimum_required(VERSION 3.14)
project(DALia VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)

add_library(
        DALia
        src/inference/i_rule.h
        src/inference/i_inferer.h
        src/inference/classicalInferer.h
        src/inference/classicalInferer.cpp
)
