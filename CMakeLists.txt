cmake_minimum_required(VERSION 3.26)
project(zuba)

set(CMAKE_CXX_STANDARD 17)

add_executable(zuba main.cpp functions.cpp functions.h my_lib.h)
