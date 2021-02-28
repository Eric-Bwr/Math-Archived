cmake_minimum_required(VERSION 3.7)
project(MathExtension)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES "Math/*.cpp" "Math/*.h")

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_NAME})

add_library(${PROJECT_NAME} ${SOURCE_FILES})