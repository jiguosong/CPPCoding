SET(INCLUDED_FILES
        ../src/rangesum.h 
        ../src/rangesum.cpp 
        rangesum_test.cpp
    )
add_executable(rangesum ${INCLUDED_FILES})
target_link_libraries(rangesum gtest gmock_main)
cotire(rangesum)
add_test(NAME rangesum_test COMMAND rangesum)
