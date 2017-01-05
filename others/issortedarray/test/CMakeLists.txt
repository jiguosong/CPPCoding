SET(INCLUDED_FILES
        ../src/issortedarray.h 
        ../src/issortedarray.cpp 
        issortedarray_test.cpp
    )
add_executable(issortedarray ${INCLUDED_FILES})
target_link_libraries(issortedarray gtest gmock_main)
cotire(issortedarray)
add_test(NAME issortedarray_test COMMAND issortedarray)
