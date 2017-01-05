SET(INCLUDED_FILES
        ../src/bstiterator.h 
        ../src/bstiterator.cpp 
        bstiterator_test.cpp
    )
add_executable(bstiterator ${INCLUDED_FILES})
target_link_libraries(bstiterator gtest gmock_main)
cotire(bstiterator)
add_test(NAME bstiterator_test COMMAND bstiterator)
