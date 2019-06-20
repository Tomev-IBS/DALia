cmake_minimum_required(VERSION 3.1)

project(DALia_tests VERSION 0.0.1)

add_subdirectory(googletest)

include_directories(googletest/googletest/include)
include_directories(../src)

add_executable(DALia_tests test_main.cpp)

target_link_libraries(DALia_tests gtest gtest_main)