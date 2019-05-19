cmake_minimum_required(VERSION 3.1)
project(dual_num)

set(CMAKE_CXX_STANDARD_REQUIRED 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic")

# set path to external dependencies
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/external)

# include external dependencies
include(googletest)

# create common variable
file(GLOB MY_SRCS
  ${PROJECT_SOURCE_DIR}/src/*.cpp
  ${PROJECT_SOURCE_DIR}/src/dual_num/*.cpp)

set(MY_INCLUDE_PATH
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/dual_num)

# sub directories
add_subdirectory(src)
add_subdirectory(test)
