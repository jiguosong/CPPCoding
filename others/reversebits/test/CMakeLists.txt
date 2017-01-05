SET(INCLUDED_FILES
        ../src/reversebits.h 
        ../src/reversebits.cpp 
        reversebits_test.cpp
    )
add_executable(reversebits ${INCLUDED_FILES})
target_link_libraries(reversebits gtest gmock_main)
cotire(reversebits)
add_test(NAME reversebits_test COMMAND reversebits)
