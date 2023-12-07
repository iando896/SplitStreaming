cmake_minimum_required(VERSION 3.16)
project(SplitStreaming)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(Python COMPONENTS Interpreter Development)
set(PYBIND11_PYTHON_VERSION 3.11.4 CACHE_STRING "")
set(pybind11_DIR "C:\\Users\\iando\\Coding\\vcpkg\\packages\\pybind11_x64-windows\\share\\pybind11")
find_package(pybind11 REQUIRED)

add_executable(SplitStreaming "main.cpp")

add_subdirectory(src)

target_link_libraries(SplitStreaming PUBLIC Classes PRIVATE pybind11::embed)

target_include_directories(SplitStreaming PRIVATE "C:\\Program Files\\Python311\\include")
target_include_directories(SplitStreaming PRIVATE ${CMAKE_SOURCE_DIR}/include)

# add_subdirectory(main)

# find_package(Python COMPONENTS Interpreter Development)

# set(PYBIND11_PYTHON_VERSION 3.11.4 CACHE_STRING "")
# find_package(pybind11 CONFIG)

# pybind11_add_module(SplitStreaming main.cpp)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


# target_link_libraries(SplitStreaming PRIVATE pybind11::embed)