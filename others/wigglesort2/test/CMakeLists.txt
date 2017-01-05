SET(INCLUDED_FILES
        ../src/wigglesort2.h 
        ../src/wigglesort2.cpp 
        wigglesort2_test.cpp
    )
add_executable(wigglesort2 ${INCLUDED_FILES})
target_link_libraries(wigglesort2 gtest gmock_main)
cotire(wigglesort2)
add_test(NAME wigglesort2_test COMMAND wigglesort2)
