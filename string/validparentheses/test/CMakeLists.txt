SET(INCLUDED_FILES
        ../src/validparentheses.h 
        ../src/validparentheses.cpp 
        validparentheses_test.cpp
    )
add_executable(validparentheses ${INCLUDED_FILES})
target_link_libraries(validparentheses gtest gmock_main)
cotire(validparentheses)
add_test(NAME validparentheses_test COMMAND validparentheses)
