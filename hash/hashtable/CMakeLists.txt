SET(INCLUDED_FILES
        hashtable.h 
        hashtable.cpp 
        hashtable_test.cpp
    )
add_executable(hashtable ${INCLUDED_FILES})
target_link_libraries(hashtable gtest gmock_main)
cotire(hashtable)
add_test(NAME hashtable_test COMMAND hashtable)
