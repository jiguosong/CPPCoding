SET(INCLUDED_FILES
        ../src/validpalindrome.h 
        ../src/validpalindrome.cpp 
        validpalindrome_test.cpp
    )
add_executable(validpalindrome ${INCLUDED_FILES})
target_link_libraries(validpalindrome gtest gmock_main)
cotire(validpalindrome)
add_test(NAME validpalindrome_test COMMAND validpalindrome)
