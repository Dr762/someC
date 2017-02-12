cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror -lm ")

set(SOURCE_FILES  linux_sysprog/file_ops.c linux_sysprog/file_ops.h)
add_executable(base_staff  ${SOURCE_FILES})
