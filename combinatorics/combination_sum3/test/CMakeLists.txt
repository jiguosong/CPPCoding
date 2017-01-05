SET(INCLUDED_FILES
        ../src/combination_sum3.h 
        ../src/combination_sum3.cpp 
        combination_sum3_test.cpp
    )
add_executable(combination_sum3 ${INCLUDED_FILES})
target_link_libraries(combination_sum3 gtest gmock_main)
cotire(combination_sum3)
add_test(NAME combination_sum3_test COMMAND combination_sum3)
