SET(INCLUDED_FILES
        ../src/firstcharacterinstring.h 
        ../src/firstcharacterinstring.cpp 
        firstcharacterinstring_test.cpp
    )
add_executable(firstcharacterinstring ${INCLUDED_FILES})
target_link_libraries(firstcharacterinstring gtest gmock_main)
cotire(firstcharacterinstring)
add_test(NAME firstcharacterinstring_test COMMAND firstcharacterinstring)
