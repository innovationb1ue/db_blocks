add_executable(test_confs test_confs.cpp)

target_link_libraries(test_confs PRIVATE confs_manager toml11)


add_test(NAME test1
        COMMAND test1)


