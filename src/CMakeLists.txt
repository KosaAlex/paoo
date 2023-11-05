cmake_minimum_required(VERSION 3.2)
project(tema1)   

add_subdirectory(FileManager)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tema1 main.cxx)

target_link_libraries(tema1 PUBLIC FileManager)

target_include_directories(tema1 PUBLIC
                           "${PROJECT_BINARY_DIR}")