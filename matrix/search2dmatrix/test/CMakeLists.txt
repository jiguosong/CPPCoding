SET(INCLUDED_FILES
        ../src/search2dmatrix.h 
        ../src/search2dmatrix.cpp 
        search2dmatrix_test.cpp
    )
add_executable(search2dmatrix ${INCLUDED_FILES})
target_link_libraries(search2dmatrix gtest gmock_main)
cotire(search2dmatrix)
add_test(NAME search2dmatrix_test COMMAND search2dmatrix)
