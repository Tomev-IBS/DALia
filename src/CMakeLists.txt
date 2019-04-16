cmake_minimum_required(VERSION 3.13)

project(DALia VERSION 0.01 DESCRIPTION "Data Analysis LIbrAry." LANGUAGES CXX)

add_library(DALia SHARED inference/i_inferer.h inference/i_rule.h)
# set_target_properties(DALia PROPERTIES LINKER_LANGUAGE CXX)