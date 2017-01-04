SET(INCLUDED_FILES
        ../src/traversal_levelorder.h 
        ../src/traversal_levelorder.cpp 
        traversal_levelorder_test.cpp
    )
add_executable(traversal_levelorder ${INCLUDED_FILES})
target_link_libraries(traversal_levelorder gtest gmock_main)
cotire(traversal_levelorder)
add_test(NAME traversal_levelorder_test COMMAND traversal_levelorder)
