cmake_minimum_required(VERSION 3.10)



# 
# Python_add_library(main main.cpp)

target_link_libraries(main PUBLIC Classes)

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/include")