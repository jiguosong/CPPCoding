SET(INCLUDED_FILES
        ../src/longestincreasingpathinmatrix.h 
        ../src/longestincreasingpathinmatrix.cpp 
        longestincreasingpathinmatrix_test.cpp
    )
add_executable(longestincreasingpathinmatrix ${INCLUDED_FILES})
target_link_libraries(longestincreasingpathinmatrix gtest gmock_main)
cotire(longestincreasingpathinmatrix)
add_test(NAME longestincreasingpathinmatrix_test COMMAND longestincreasingpathinmatrix)
