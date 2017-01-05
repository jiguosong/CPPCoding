SET(INCLUDED_FILES
        ../src/combination_sum.h 
        ../src/combination_sum.cpp 
        combination_sum_test.cpp
    )
add_executable(combination_sum ${INCLUDED_FILES})
target_link_libraries(combination_sum gtest gmock_main)
cotire(combination_sum)
add_test(NAME combination_sum_test COMMAND combination_sum)
