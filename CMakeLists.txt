cmake_minimum_required(VERSION 3.29)
project(RTX)
set(CMAKE_CXX_STANDARD 20)

add_definitions(-DPROJECT_ROOT="${CMAKE_SOURCE_DIR}")

add_library(STBI INTERFACE)
target_include_directories(STBI INTERFACE lib/stbi)


set(TEST_FILE "test/02 something.cpp")
add_executable(TEST ${TEST_FILE})
target_link_libraries(TEST PRIVATE STBI)