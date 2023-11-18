add_library(FileManager STATIC FileManager.cpp)
target_include_directories(FileManager INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
add_library(JavaFileManager STATIC JavaFileManager.cpp)
add_library(CppFileManager STATIC CppFileManager.cpp)
