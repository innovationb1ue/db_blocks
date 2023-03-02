add_library(sstable sstable.hpp.cpp)

set_target_properties(sstable PROPERTIES LINKER_LANGUAGE CXX)

target_link_directories(sstable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(sstable PRIVATE spdlog)
target_link_libraries(sstable PRIVATE data_structure)