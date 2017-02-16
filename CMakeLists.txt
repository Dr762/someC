cmake_minimum_required(VERSION 2.8.4)
project(someC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} Wall -Werror -lm ")

set(SOURCE_FILES  linux_sysprog/file_ops.c linux_sysprog/file_ops.h linux_sysprog/small_daemon.c linux_sysprog/cpu_affinity.c linux_sysprog/rr_priority_range.c linux_sysprog/set_highest_priority.c linux_sysprog/rr_interval.c linux_sysprog/rlimits.c)
add_executable(base_staff  ${SOURCE_FILES})
