SET(INCLUDED_FILES
        ../src/alignedAllocate.h 
        ../src/alignedAllocate.cpp 
        alignedAllocate_test.cpp
    )
add_executable(alignedAllocate ${INCLUDED_FILES})
target_link_libraries(alignedAllocate gtest gmock_main)
cotire(alignedAllocate)
add_test(NAME alignedAllocate_test COMMAND alignedAllocate)
