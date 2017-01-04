SET(INCLUDED_FILES
        ../src/maxsubsequncesum.h 
        ../src/maxsubsequncesum.cpp 
        maxsubsequncesum_test.cpp
    )
add_executable(maxsubsequncesum ${INCLUDED_FILES})
target_link_libraries(maxsubsequncesum gtest gmock_main)
cotire(maxsubsequncesum)
add_test(NAME maxsubsequncesum_test COMMAND maxsubsequncesum)
