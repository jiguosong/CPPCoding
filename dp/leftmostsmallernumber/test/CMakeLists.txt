SET(INCLUDED_FILES
        ../src/leftmostsmallernumber.h 
        ../src/leftmostsmallernumber.cpp 
        leftmostsmallernumber_test.cpp
    )
add_executable(leftmostsmallernumber ${INCLUDED_FILES})
target_link_libraries(leftmostsmallernumber gtest gmock_main)
cotire(leftmostsmallernumber)
add_test(NAME leftmostsmallernumber_test COMMAND leftmostsmallernumber)
