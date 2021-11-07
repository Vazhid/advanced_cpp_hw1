cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")

set(LIB_SOURCE_FILE foo.c)
add_library(server STATIC ${LIB_SOURCE_FILE})

add_compile_options("-lgcov --coverage")

add_executable(main main.c)
target_link_libraries(main server)


