cmake_minimum_required(VERSION 3.14)

# Day 1 executable
add_executable(day1
  day1.cpp
  day1.h)

# Confirm strictly to C++20
target_compile_features(day1 PUBLIC cxx_std_20)
set_target_properties(day1 PROPERTIES
  CXX_EXTENSIONS OFF
  CXX_STANDARD_REQUIRED ON)

# Link any required libraries to this console executable (currently none needed for hello world)
# target_link_libraries(day1 PRIVATE ...)

# Copy input.txt from aoc-questions-inputs/2025/day1/ to build directory
configure_file(${CMAKE_SOURCE_DIR}/aoc-questions-inputs/2025/day1/input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)