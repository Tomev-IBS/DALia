cmake_minimum_required(VERSION 3.1)

project(DALia)

add_library(DALia SHARED test.cpp)
set_target_properties(DALia PROPERTIES LINKER_LANGUAGE CXX)
