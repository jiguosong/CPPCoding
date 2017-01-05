SET(INCLUDED_FILES
        ../src/minimumheighttree.h 
        ../src/minimumheighttree.cpp 
        minimumheighttree_test.cpp
    )
add_executable(minimumheighttree ${INCLUDED_FILES})
target_link_libraries(minimumheighttree gtest gmock_main)
cotire(minimumheighttree)
add_test(NAME minimumheighttree_test COMMAND minimumheighttree)
