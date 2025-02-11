cmake_minimum_required(VERSION 3.29)
project(RTX)
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)


# STB Image Library Headers
add_library(STBI INTERFACE)
target_include_directories(STBI INTERFACE lib/stbi)

# glm Library Fetch
FetchContent_Declare(glm GIT_REPOSITORY https://github.com/g-truc/glm.git GIT_TAG 1.0.1)
FetchContent_MakeAvailable(glm)


add_definitions(-DPROJECT_ROOT="${CMAKE_SOURCE_DIR}")
set(TEST_FILE "test/01 image read write.cpp")
add_executable(TEST ${TEST_FILE})

target_link_libraries(TEST PRIVATE STBI)
target_link_libraries(TEST PRIVATE glm)