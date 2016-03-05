cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror ")

set(SOURCE_FILES  data_structures/trees/binary/bintree.h data_structures/trees/binary/bintree.c data_structures/trees/binary/bintree_demo.c)
add_executable(data_structures  ${SOURCE_FILES})