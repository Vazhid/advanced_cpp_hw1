cmake_minimum_required(VERSION 3.19)
project(iz1)

set(CMAKE_C_STANDARD 99)

add_library(lib STATIC foo.c foo.h)
add_executable(output main.c)