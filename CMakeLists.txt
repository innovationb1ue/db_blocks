cmake_minimum_required(VERSION 3.24)
project(db_blocks)

set(CMAKE_CXX_STANDARD 17)


# executables
add_executable(db_blocks src/main.cpp)
add_executable(test src/main2.cpp)


# get the library get built
add_subdirectory(src/sstable)
# link the new library with the executable target
target_link_libraries(db_blocks PUBLIC sstable)
# specify the library header file location (so .h files can be found in this executable context, ie. in main.cpp)
target_include_directories(db_blocks PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/src/sstable"
        )

