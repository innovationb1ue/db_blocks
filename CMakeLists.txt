cmake_minimum_required(VERSION 3.24)
project(db_blocks)

set(CMAKE_CXX_STANDARD 17)

# this control whether enable logger
set(use_logger ON)

IF (${use_logger})
    message("using logger spdlog")
    add_subdirectory(libs/spdlog)
else ()
    message("NO logger mode")
endif ()

# third party
add_subdirectory(libs/toml11)

# add path for searching include files
include_directories(src)

# executables
add_executable(main src/main.cpp)

# get the libraries get built
add_subdirectory(src/)
add_subdirectory(src/confs)
add_subdirectory(src/page)
add_subdirectory(src/data_structure)
add_subdirectory(src/concurrency)
add_subdirectory(src/db)

enable_testing()
# test directory
add_subdirectory(test)

# link the new library with the executable target
target_link_libraries(main INTERFACE data_structure)
target_link_libraries(main PUBLIC page)
target_link_libraries(main PRIVATE spdlog)
target_link_libraries(main PRIVATE toml11)

# specify the library header file location (so .h files can be found in this executable context, ie. in main.cpp)
target_include_directories(main PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/src/"
        )









