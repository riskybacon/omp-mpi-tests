cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME test_mpi_omp)
set(TARGET_NAME test_mpi_omp)
set(SOURCES test_mpi_omp.c)

project(${PROJECT_NAME})

find_package(MPI)
if (MPI_FOUND)
   include_directories(${MPI_INCLUDE_PATH})
else()
   message(ERROR "MPI not found, cannot build ${PROJECT_NAME}")
endif()

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
else()
    message(ERROR "OpenMP not found, cannot build test")
endif()

add_executable(${TARGET_NAME} ${SOURCES})
target_link_libraries(${TARGET_NAME} ${MPI_LIBRARIES})

if(MPI_LINK_FLAGS)
   set_target_properties(${TARGET_NAME} PROPERTIES
      LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()

if(MPI_COMPILE_FLAGS)
  set_target_properties(${TARGET_NAME} PROPERTIES
    COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()
