cmake_minimum_required(VERSION 3.13)
project(Codes)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-static-libgcc ")


add_executable(a POJ/1064.cpp)
set_target_properties(a PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")