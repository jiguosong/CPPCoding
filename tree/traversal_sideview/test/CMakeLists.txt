SET(INCLUDED_FILES
        ../src/traversal_sideview.h 
        ../src/traversal_sideview.cpp 
        traversal_sideview_test.cpp
    )
add_executable(traversal_sideview ${INCLUDED_FILES})
target_link_libraries(traversal_sideview gtest gmock_main)
cotire(traversal_sideview)
add_test(NAME traversal_sideview_test COMMAND traversal_sideview)
