SET(INCLUDED_FILES
        ../src/parsestr2tree.h 
        ../src/parsestr2tree.cpp 
        parsestr2tree_test.cpp
    )
add_executable(parsestr2tree ${INCLUDED_FILES})
target_link_libraries(parsestr2tree gtest gmock_main)
cotire(parsestr2tree)
add_test(NAME parsestr2tree_test COMMAND parsestr2tree)
