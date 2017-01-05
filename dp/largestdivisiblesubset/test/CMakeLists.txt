SET(INCLUDED_FILES
        ../src/largestdivisiblesubset.h 
        ../src/largestdivisiblesubset.cpp 
        largestdivisiblesubset_test.cpp
    )
add_executable(largestdivisiblesubset ${INCLUDED_FILES})
target_link_libraries(largestdivisiblesubset gtest gmock_main)
cotire(largestdivisiblesubset)
add_test(NAME largestdivisiblesubset_test COMMAND largestdivisiblesubset)
