SET(INCLUDED_FILES
        ../src/longestcommonsubsequence.h 
        ../src/longestcommonsubsequence.cpp 
        longestcommonsubsequence_test.cpp
    )
add_executable(longestcommonsubsequence ${INCLUDED_FILES})
target_link_libraries(longestcommonsubsequence gtest gmock_main)
cotire(longestcommonsubsequence)
add_test(NAME longestcommonsubsequence_test COMMAND longestcommonsubsequence)
