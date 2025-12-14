cmake_minimum_required(VERSION 3.14)

project(seed
  VERSION 0.1.0
  DESCRIPTION "A C++ application"
  HOMEPAGE_URL "https://github.com/legends2k/cpp-vcpkg-seed"
  LANGUAGES CXX)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not supported. "
    "Please delete 'CMakeCache.txt' and 'CMakeFiles/' first.")
endif()

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# https://vcpkg.io/en/docs/examples/manifest-mode-cmake.html

# Add subdirectories
add_subdirectory(day1)
add_subdirectory(day2)
add_subdirectory(day3)
add_subdirectory(day4)
add_subdirectory(day5)
add_subdirectory(day6)
add_subdirectory(day7)
