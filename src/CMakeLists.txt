add_library(Classes StreamingService.cpp User.cpp UserDatabase.cpp)

target_include_directories(Classes PUBLIC "${PROJECT_SOURCE_DIR}/include")