SET(INCLUDED_FILES
        ../src/longestvalidparentheses.h 
        ../src/longestvalidparentheses.cpp 
        longestvalidparentheses_test.cpp
    )
add_executable(longestvalidparentheses ${INCLUDED_FILES})
target_link_libraries(longestvalidparentheses gtest gmock_main)
cotire(longestvalidparentheses)
add_test(NAME longestvalidparentheses_test COMMAND longestvalidparentheses)
