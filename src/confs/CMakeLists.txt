add_library(confs_manager parser.h parser.cpp)


target_link_libraries(confs_manager PRIVATE spdlog)
target_link_libraries(confs_manager PRIVATE toml11)

