cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror")

set(SOURCE_FILES data_structures/double_linked_list/double_linked_list_demo.c data_structures/double_linked_list/double_list.h data_structures/double_linked_list/double_list.c)
add_executable(data_structures  ${SOURCE_FILES})