SET(INCLUDED_FILES
        ../src/rotatearray.h 
        ../src/rotatearray.cpp 
        rotatearray_test.cpp
    )
add_executable(rotatearray ${INCLUDED_FILES})
target_link_libraries(rotatearray gtest gmock_main)
cotire(rotatearray)
add_test(NAME rotatearray_test COMMAND rotatearray)
