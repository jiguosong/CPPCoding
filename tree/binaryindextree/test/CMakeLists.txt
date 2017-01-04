SET(INCLUDED_FILES
        ../src/binaryindextree.h 
        ../src/binaryindextree.cpp 
        binaryindextree_test.cpp
    )
add_executable(binaryindextree ${INCLUDED_FILES})
target_link_libraries(binaryindextree gtest gmock_main)
cotire(binaryindextree)
add_test(NAME binaryindextree_test COMMAND binaryindextree)
