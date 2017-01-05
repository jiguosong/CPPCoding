SET(INCLUDED_FILES
        ../src/minimumpathsum.h 
        ../src/minimumpathsum.cpp 
        minimumpathsum_test.cpp
    )
add_executable(minimumpathsum ${INCLUDED_FILES})
target_link_libraries(minimumpathsum gtest gmock_main)
cotire(minimumpathsum)
add_test(NAME minimumpathsum_test COMMAND minimumpathsum)
