SET(INCLUDED_FILES
        ../src/reverselinkedlist.h 
        ../src/reverselinkedlist.cpp 
        reverselinkedlist_test.cpp
    )
add_executable(reverselinkedlist ${INCLUDED_FILES})
target_link_libraries(reverselinkedlist gtest gmock_main)
cotire(reverselinkedlist)
add_test(NAME reverselinkedlist_test COMMAND reverselinkedlist)
