cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror ")

set(SOURCE_FILES data_structures/sets/set_demo.c data_structures/sets/set.h data_structures/sets/set.c
        data_structures/sets/list.c data_structures/sets/list.h)
add_executable(data_structures  ${SOURCE_FILES})