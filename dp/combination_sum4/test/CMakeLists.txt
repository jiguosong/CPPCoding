SET(INCLUDED_FILES
        ../src/combination_sum4.h 
        ../src/combination_sum4.cpp 
        combination_sum4_test.cpp
    )
add_executable(combination_sum4 ${INCLUDED_FILES})
target_link_libraries(combination_sum4 gtest gmock_main)
cotire(combination_sum4)
add_test(NAME combination_sum4_test COMMAND combination_sum4)
