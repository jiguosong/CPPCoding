SET(INCLUDED_FILES
        ../src/segmenttree.h 
        ../src/segmenttree.cpp 
        segmenttree_test.cpp
    )
add_executable(segmenttree ${INCLUDED_FILES})
target_link_libraries(segmenttree gtest gmock_main)
cotire(segmenttree)
add_test(NAME segmenttree_test COMMAND segmenttree)
