SET(INCLUDED_FILES
        ../src/combination_sum2.h 
        ../src/combination_sum2.cpp 
        combination_sum2_test.cpp
    )
add_executable(combination_sum2 ${INCLUDED_FILES})
target_link_libraries(combination_sum2 gtest gmock_main)
cotire(combination_sum2)
add_test(NAME combination_sum2_test COMMAND combination_sum2)
