SET(INCLUDED_FILES
        ../src/longestpalindrome.h 
        ../src/longestpalindrome.cpp 
        longestpalindrome_test.cpp
    )
add_executable(longestpalindrome ${INCLUDED_FILES})
target_link_libraries(longestpalindrome gtest gmock_main)
cotire(longestpalindrome)
add_test(NAME longestpalindrome_test COMMAND longestpalindrome)
