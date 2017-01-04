SET(INCLUDED_FILES
        ../src/uniqueBSTs.h 
        ../src/uniqueBSTs.cpp 
        uniqueBSTs_test.cpp
    )
add_executable(uniqueBSTs ${INCLUDED_FILES})
target_link_libraries(uniqueBSTs gtest gmock_main)
cotire(uniqueBSTs)
add_test(NAME uniqueBSTs_test COMMAND uniqueBSTs)
