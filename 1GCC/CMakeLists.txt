cmake_minimum_required(VERSION 3.7)
project(1GCC_2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c md5.h md5.c)
add_executable(1GCC_2 ${SOURCE_FILES})