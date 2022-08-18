cmake_minimum_required(VERSION 3.7)
project(Math)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE HEADER_FILES "Math/*.h")

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_NAME})

add_library(${PROJECT_NAME} ${HEADER_FILES})