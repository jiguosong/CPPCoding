SET(INCLUDED_FILES
        ../src/deletenodeinBST.h 
        ../src/deletenodeinBST.cpp 
        deletenodeinBST_test.cpp
    )
add_executable(deletenodeinBST ${INCLUDED_FILES})
target_link_libraries(deletenodeinBST gtest gmock_main)
cotire(deletenodeinBST)
add_test(NAME deletenodeinBST_test COMMAND deletenodeinBST)
