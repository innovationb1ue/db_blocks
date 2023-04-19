# enable testing functionality

#set(CMAKE_BUILD_TYPE DEBUG)

# testing binary
add_executable(cpp_test test.cpp)
add_executable(test_skiplist test_skiplist.cpp)
add_executable(test_confs test_confs.cpp)
add_executable(test_db test_db.cpp)
add_executable(test_lock_manager test_lock_manager.cpp)

target_link_libraries(test_skiplist PRIVATE skiplist)
target_link_libraries(test_confs PRIVATE confs_manager toml11)
target_link_libraries(test_db PRIVATE toml11)
target_link_libraries(test_lock_manager PRIVATE lock_manager)


# define tests
add_test(
        NAME cpp_test
        COMMAND $<TARGET_FILE:cpp_test>
)
add_test(
        NAME test_skiplist
        COMMAND $<TARGET_FILE:test_skiplist>
)
add_test(
        NAME test_db
        COMMAND $<TARGET_FILE:test_db>
)

add_test(
        NAME test_lock_manager
        COMMAND $<TARGET_FILE:test_lock_manager>
)





