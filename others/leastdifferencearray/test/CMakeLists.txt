SET(INCLUDED_FILES
        ../src/leastdifferencearray.h 
        ../src/leastdifferencearray.cpp 
        leastdifferencearray_test.cpp
    )
add_executable(leastdifferencearray ${INCLUDED_FILES})
target_link_libraries(leastdifferencearray gtest gmock_main)
cotire(leastdifferencearray)
add_test(NAME leastdifferencearray_test COMMAND leastdifferencearray)
