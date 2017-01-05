SET(INCLUDED_FILES
        ../src/spiralmatrix.h 
        ../src/spiralmatrix.cpp 
        spiralmatrix_test.cpp
    )
add_executable(spiralmatrix ${INCLUDED_FILES})
target_link_libraries(spiralmatrix gtest gmock_main)
cotire(spiralmatrix)
add_test(NAME spiralmatrix_test COMMAND spiralmatrix)
