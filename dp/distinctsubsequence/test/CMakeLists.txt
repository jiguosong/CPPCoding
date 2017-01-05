SET(INCLUDED_FILES
        ../src/distinctsubsequence.h 
        ../src/distinctsubsequence.cpp 
        distinctsubsequence_test.cpp
    )
add_executable(distinctsubsequence ${INCLUDED_FILES})
target_link_libraries(distinctsubsequence gtest gmock_main)
cotire(distinctsubsequence)
add_test(NAME distinctsubsequence_test COMMAND distinctsubsequence)
