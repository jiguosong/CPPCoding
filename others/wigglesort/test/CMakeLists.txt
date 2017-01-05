SET(INCLUDED_FILES
        ../src/wigglesort.h 
        ../src/wigglesort.cpp 
        wigglesort_test.cpp
    )
add_executable(wigglesort ${INCLUDED_FILES})
target_link_libraries(wigglesort gtest gmock_main)
cotire(wigglesort)
add_test(NAME wigglesort_test COMMAND wigglesort)
