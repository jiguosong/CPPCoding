SET(INCLUDED_FILES
        ../src/verifypreorderBT.h 
        ../src/verifypreorderBT.cpp 
        verifypreorderBT_test.cpp
    )
add_executable(verifypreorderBT ${INCLUDED_FILES})
target_link_libraries(verifypreorderBT gtest gmock_main)
cotire(verifypreorderBT)
add_test(NAME verifypreorderBT_test COMMAND verifypreorderBT)
