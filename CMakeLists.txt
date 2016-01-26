cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror")

set(SOURCE_FILES base.c base.h )
add_executable(base.out ${SOURCE_FILES})