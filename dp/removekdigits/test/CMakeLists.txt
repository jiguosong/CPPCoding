SET(INCLUDED_FILES
        ../src/removekdigits.h 
        ../src/removekdigits.cpp 
        removekdigits_test.cpp
    )
add_executable(removekdigits ${INCLUDED_FILES})
target_link_libraries(removekdigits gtest gmock_main)
cotire(removekdigits)
add_test(NAME removekdigits_test COMMAND removekdigits)
