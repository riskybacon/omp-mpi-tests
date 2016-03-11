# Require at least version 2.8 of CMake
cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME test_mpi)
set(TARGET_NAME test_mpi)
set(SOURCES test_mpi.c)

project(${PROJECT_NAME})

find_package(MPI)
if (MPI_FOUND)
   include_directories(${MPI_INCLUDE_PATH})
else()
   message(ERROR "MPI not found, cannot build ${PROJECT_NAME}")
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
