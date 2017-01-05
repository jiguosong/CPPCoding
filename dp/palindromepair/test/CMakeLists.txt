SET(INCLUDED_FILES
        ../src/palindromepair.h 
        ../src/palindromepair.cpp 
        palindromepair_test.cpp
    )
add_executable(palindromepair ${INCLUDED_FILES})
target_link_libraries(palindromepair gtest gmock_main)
cotire(palindromepair)
add_test(NAME palindromepair_test COMMAND palindromepair)
