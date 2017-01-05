SET(INCLUDED_FILES
        ../src/permutation.h 
        ../src/permutation.cpp 
        permutation_test.cpp
    )
add_executable(permutation ${INCLUDED_FILES})
target_link_libraries(permutation gtest gmock_main)
cotire(permutation)
add_test(NAME permutation_test COMMAND permutation)
