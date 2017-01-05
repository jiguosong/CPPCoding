SET(INCLUDED_FILES
        ../src/createmaxnumber.h 
        ../src/createmaxnumber.cpp 
        createmaxnumber_test.cpp
    )
add_executable(createmaxnumber ${INCLUDED_FILES})
target_link_libraries(createmaxnumber gtest gmock_main)
cotire(createmaxnumber)
add_test(NAME createmaxnumber_test COMMAND createmaxnumber)
