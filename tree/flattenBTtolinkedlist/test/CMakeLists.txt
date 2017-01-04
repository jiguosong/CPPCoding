SET(INCLUDED_FILES
        ../src/flattenBTtolinkedlist.h 
        ../src/flattenBTtolinkedlist.cpp 
        flattenBTtolinkedlist_test.cpp
    )
add_executable(flattenBTtolinkedlist ${INCLUDED_FILES})
target_link_libraries(flattenBTtolinkedlist gtest gmock_main)
cotire(flattenBTtolinkedlist)
add_test(NAME flattenBTtolinkedlist_test COMMAND flattenBTtolinkedlist)
