cmake_minimum_required(VERSION 3.15)
project(2611_group)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2611_group
        MaxHeap.cpp
        MaxHeap.h
        SortAlgorithms.cpp
        SortAlgorithms.h
        Sorting.cpp)
