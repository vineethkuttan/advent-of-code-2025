cmake_minimum_required(VERSION 3.14)

# Day 7 executable
add_executable(day7
  day7.cpp
  day7.h)

# Confirm strictly to C++20
target_compile_features(day7 PUBLIC cxx_std_20)
set_target_properties(day7 PROPERTIES
  CXX_EXTENSIONS OFF
  CXX_STANDARD_REQUIRED ON)

# Link any required libraries to this console executable (currently none needed for hello world)
# target_link_libraries(day7 PRIVATE ...)

# Copy input.txt from aoc-questions-inputs/2025/day7/ to build directory
configure_file(${CMAKE_SOURCE_DIR}/aoc-questions-inputs/2025/day7/input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)