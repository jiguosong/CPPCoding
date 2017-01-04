SET(INCLUDED_FILES
        ../src/traversal_inorder.h 
        ../src/traversal_inorder.cpp 
        traversal_inorder_test.cpp
    )
add_executable(traversal_inorder ${INCLUDED_FILES})
target_link_libraries(traversal_inorder gtest gmock_main)
cotire(traversal_inorder)
add_test(NAME traversal_inorder_test COMMAND traversal_inorder)
