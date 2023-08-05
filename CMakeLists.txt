cmake_minimum_required(VERSION 3.10)

project(SplitStreaming)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

add_executable(SplitStreaming main.cpp)

target_link_libraries(SplitStreaming PUBLIC Classes)

target_include_directories(SplitStreaming PUBLIC "${PROJECT_SOURCE_DIR}/include")