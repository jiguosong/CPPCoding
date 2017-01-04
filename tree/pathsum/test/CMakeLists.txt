SET(INCLUDED_FILES
        ../src/pathsum.h 
        ../src/pathsum.cpp 
        pathsum_test.cpp
    )
add_executable(pathsum ${INCLUDED_FILES})
target_link_libraries(pathsum gtest gmock_main)
cotire(pathsum)
add_test(NAME pathsum_test COMMAND pathsum)
