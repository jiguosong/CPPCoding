SET(INCLUDED_FILES
        ../src/findminrottedarray.h 
        ../src/findminrottedarray.cpp 
        findminrottedarray_test.cpp
    )
add_executable(findminrottedarray ${INCLUDED_FILES})
target_link_libraries(findminrottedarray gtest gmock_main)
cotire(findminrottedarray)
add_test(NAME findminrottedarray_test COMMAND findminrottedarray)
