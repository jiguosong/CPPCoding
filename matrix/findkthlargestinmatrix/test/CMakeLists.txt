SET(INCLUDED_FILES
        ../src/findkthlargestinmatrix.h 
        ../src/findkthlargestinmatrix.cpp 
        findkthlargestinmatrix_test.cpp
    )
add_executable(findkthlargestinmatrix ${INCLUDED_FILES})
target_link_libraries(findkthlargestinmatrix gtest gmock_main)
cotire(findkthlargestinmatrix)
add_test(NAME findkthlargestinmatrix_test COMMAND findkthlargestinmatrix)
