SET(INCLUDED_FILES
        ../src/searchRangeBST.h 
        ../src/searchRangeBST.cpp 
        searchRangeBST_test.cpp
    )
add_executable(searchRangeBST ${INCLUDED_FILES})
target_link_libraries(searchRangeBST gtest gmock_main)
cotire(searchRangeBST)
add_test(NAME searchRangeBST_test COMMAND searchRangeBST)
