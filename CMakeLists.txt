cmake_minimum_required(VERSION 3.13)
project(Codes)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WARN_DEPRECATED true)
add_executable(a NCKUOnlineJudge/17.c)
set_target_properties(a PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")
