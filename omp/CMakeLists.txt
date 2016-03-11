# Require at least version 2.8 of CMake
cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME test_omp)
project(${PROJECT_NAME})

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
else()
    message(ERROR "OpenMP not found, cannot build test")
endif()

add_executable(${PROJECT_NAME}
   test_omp.c
)
