SET(INCLUDED_FILES
        ../src/reversewords.h 
        ../src/reversewords.cpp 
        reversewords_test.cpp
    )
add_executable(reversewords ${INCLUDED_FILES})
target_link_libraries(reversewords gtest gmock_main)
cotire(reversewords)
add_test(NAME reversewords_test COMMAND reversewords)
