cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror ")

set(SOURCE_FILES base_staff/bit_ops.c  base_staff/bit_ops.h)
add_executable(base_staff  ${SOURCE_FILES})
