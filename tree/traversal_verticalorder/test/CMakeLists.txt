SET(INCLUDED_FILES
        ../src/traversal_verticalorder.h 
        ../src/traversal_verticalorder.cpp 
        traversal_verticalorder_test.cpp
    )
add_executable(traversal_verticalorder ${INCLUDED_FILES})
target_link_libraries(traversal_verticalorder gtest gmock_main)
cotire(traversal_verticalorder)
add_test(NAME traversal_verticalorder_test COMMAND traversal_verticalorder)
