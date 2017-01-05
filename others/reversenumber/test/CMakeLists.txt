SET(INCLUDED_FILES
        ../src/reversenumber.h 
        ../src/reversenumber.cpp 
        reversenumber_test.cpp
    )
add_executable(reversenumber ${INCLUDED_FILES})
target_link_libraries(reversenumber gtest gmock_main)
cotire(reversenumber)
add_test(NAME reversenumber_test COMMAND reversenumber)
