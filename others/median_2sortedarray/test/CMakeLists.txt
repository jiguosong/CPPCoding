SET(INCLUDED_FILES
        ../src/median_2sortedarray.h 
        ../src/median_2sortedarray.cpp 
        median_2sortedarray_test.cpp
    )
add_executable(median_2sortedarray ${INCLUDED_FILES})
target_link_libraries(median_2sortedarray gtest gmock_main)
cotire(median_2sortedarray)
add_test(NAME median_2sortedarray_test COMMAND median_2sortedarray)
