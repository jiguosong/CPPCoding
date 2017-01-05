SET(INCLUDED_FILES
        ../src/partitionpalindrome.h 
        ../src/partitionpalindrome.cpp 
        partitionpalindrome_test.cpp
    )
add_executable(partitionpalindrome ${INCLUDED_FILES})
target_link_libraries(partitionpalindrome gtest gmock_main)
cotire(partitionpalindrome)
add_test(NAME partitionpalindrome_test COMMAND partitionpalindrome)
