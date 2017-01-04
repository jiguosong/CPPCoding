SET(INCLUDED_FILES
        ../src/longestconsecutivesequence.h 
        ../src/longestconsecutivesequence.cpp 
        longestconsecutivesequence_test.cpp
    )
add_executable(longestconsecutivesequence ${INCLUDED_FILES})
target_link_libraries(longestconsecutivesequence gtest gmock_main)
cotire(longestconsecutivesequence)
add_test(NAME longestconsecutivesequence_test COMMAND longestconsecutivesequence)
