SET(INCLUDED_FILES
        ../src/add2number.h 
        ../src/add2number.cpp 
        add2number_test.cpp
    )
add_executable(add2number ${INCLUDED_FILES})
target_link_libraries(add2number gtest gmock_main)
cotire(add2number)
add_test(NAME add2number_test COMMAND add2number)
