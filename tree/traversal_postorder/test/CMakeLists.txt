SET(INCLUDED_FILES
        ../src/traversal_postorder.h 
        ../src/traversal_postorder.cpp 
        traversal_postorder_test.cpp
    )
add_executable(traversal_postorder ${INCLUDED_FILES})
target_link_libraries(traversal_postorder gtest gmock_main)
cotire(traversal_postorder)
add_test(NAME traversal_postorder_test COMMAND traversal_postorder)
