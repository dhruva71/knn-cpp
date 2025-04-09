cmake_minimum_required(VERSION 3.20)
project(knn_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(knn_cpp main.cpp
        DataPoint.cpp
        DataPoint.h
        loadcsv.h
        loadcsv.cpp)
