SET(INCLUDED_FILES
        ../src/sqrtx.h 
        ../src/sqrtx.cpp 
        sqrtx_test.cpp
    )
add_executable(sqrtx ${INCLUDED_FILES})
target_link_libraries(sqrtx gtest gmock_main)
cotire(sqrtx)
add_test(NAME sqrtx_test COMMAND sqrtx)
