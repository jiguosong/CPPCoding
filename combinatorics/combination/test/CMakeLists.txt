SET(INCLUDED_FILES
        ../src/combination.h 
        ../src/combination.cpp 
        combination_test.cpp
    )
add_executable(combination ${INCLUDED_FILES})
target_link_libraries(combination gtest gmock_main)
cotire(combination)
add_test(NAME combination_test COMMAND combination)
