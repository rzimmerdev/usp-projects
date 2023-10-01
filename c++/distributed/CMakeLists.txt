cmake_minimum_required(VERSION 3.26)
project(distributed)

set(CMAKE_CXX_STANDARD 17)

# Compile with -O3
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(distributed main.cpp)
