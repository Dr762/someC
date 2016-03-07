cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror ")

set(SOURCE_FILES data_structures/set/list.h data_structures/set/list.c data_structures/set/set.h data_structures/set/set.c data_structures/set/set_demo.c )
add_executable(base_staff  ${SOURCE_FILES})
