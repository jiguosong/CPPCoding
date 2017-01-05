SET(INCLUDED_FILES
        ../src/generateparentheses.h 
        ../src/generateparentheses.cpp 
        generateparentheses_test.cpp
    )
add_executable(generateparentheses ${INCLUDED_FILES})
target_link_libraries(generateparentheses gtest gmock_main)
cotire(generateparentheses)
add_test(NAME generateparentheses_test COMMAND generateparentheses)
