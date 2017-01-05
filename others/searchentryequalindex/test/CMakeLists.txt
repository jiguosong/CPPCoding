SET(INCLUDED_FILES
        ../src/searchentryequalindex.h 
        ../src/searchentryequalindex.cpp 
        searchentryequalindex_test.cpp
    )
add_executable(searchentryequalindex ${INCLUDED_FILES})
target_link_libraries(searchentryequalindex gtest gmock_main)
cotire(searchentryequalindex)
add_test(NAME searchentryequalindex_test COMMAND searchentryequalindex)
