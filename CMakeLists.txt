cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror")

set(SOURCE_FILES data_structures/linked_list/linked_list_demo.c data_structures/linked_list/list.h data_structures/linked_list/list.c data_structures/ds_base.h)
add_executable(data_structures  ${SOURCE_FILES})