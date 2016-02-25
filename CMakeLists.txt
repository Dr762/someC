cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror")

set(SOURCE_FILES data_structures/circled_list/circular_list.c data_structures/circled_list/circular_list.h
        data_structures/circled_list/circular_list_demo.c)
add_executable(data_structures  ${SOURCE_FILES})