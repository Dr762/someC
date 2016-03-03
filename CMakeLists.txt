cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror ")

set(SOURCE_FILES data_structures/hash_tables/chained_hashtable/list.c data_structures/hash_tables/chained_hashtable/list.h data_structures/hash_tables/chained_hashtable/chtbl.h data_structures/hash_tables/chained_hashtable/chtbl.c data_structures/hash_tables/chained_hashtable/chtbl_demo.c)
add_executable(data_structures  ${SOURCE_FILES})