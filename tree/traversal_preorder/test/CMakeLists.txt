SET(INCLUDED_FILES
        ../src/traversal_preorder.h 
        ../src/traversal_preorder.cpp 
        traversal_preorder_test.cpp
    )
add_executable(traversal_preorder ${INCLUDED_FILES})
target_link_libraries(traversal_preorder gtest gmock_main)
cotire(traversal_preorder)
add_test(NAME traversal_preorder_test COMMAND traversal_preorder)
