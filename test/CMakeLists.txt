


# enable testing functionality
enable_testing()

# testing binary
add_executable(cpp_test test.cpp)
add_executable(test_skiplist test_skiplist.cpp)
add_executable(test_confs test_confs.cpp)

target_link_libraries(test_skiplist PRIVATE skiplist)
target_link_libraries(test_confs PRIVATE confs_manager toml11)


# define tests
add_test(
        NAME cpp_test
        COMMAND $<TARGET_FILE:cpp_test>
)
add_test(
        NAME test_skiplist
        COMMAND $<TARGET_FILE:test_skiplist>
)


