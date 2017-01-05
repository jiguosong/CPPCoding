SET(INCLUDED_FILES
        ../src/dividearray.h 
        ../src/dividearray.cpp 
        dividearray_test.cpp
    )
add_executable(dividearray ${INCLUDED_FILES})
target_link_libraries(dividearray gtest gmock_main)
cotire(dividearray)
add_test(NAME dividearray_test COMMAND dividearray)
