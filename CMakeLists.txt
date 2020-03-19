cmake_minimum_required(VERSION 3.13)
project(hqmult C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lpthread")
add_executable(hqmult main.c)