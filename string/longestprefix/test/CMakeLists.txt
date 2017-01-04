SET(INCLUDED_FILES
        ../src/longestprefix.h 
        ../src/longestprefix.cpp 
        longestprefix_test.cpp
    )
add_executable(longestprefix ${INCLUDED_FILES})
target_link_libraries(longestprefix gtest gmock_main)
cotire(longestprefix)
add_test(NAME longestprefix_test COMMAND longestprefix)
