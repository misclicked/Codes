cmake_minimum_required(VERSION 3.13)
project(Codes)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_WARN_DEPRECATED true)
add_definitions(-DOUO)

add_executable(a Codeforces/CurrentContest/pA.cpp)
set_target_properties(a PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")
