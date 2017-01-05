SET(INCLUDED_FILES
        ../src/minimumsubarraylen.h 
        ../src/minimumsubarraylen.cpp 
        minimumsubarraylen_test.cpp
    )
add_executable(minimumsubarraylen ${INCLUDED_FILES})
target_link_libraries(minimumsubarraylen gtest gmock_main)
cotire(minimumsubarraylen)
add_test(NAME minimumsubarraylen_test COMMAND minimumsubarraylen)
