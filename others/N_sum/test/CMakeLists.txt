SET(INCLUDED_FILES
        ../src/N_sum.h 
        ../src/N_sum.cpp 
        N_sum_test.cpp
    )
add_executable(N_sum ${INCLUDED_FILES})
target_link_libraries(N_sum gtest gmock_main)
cotire(N_sum)
add_test(NAME N_sum_test COMMAND N_sum)
