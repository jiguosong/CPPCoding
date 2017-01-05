SET(INCLUDED_FILES
        ../src/swapnodesinpairs.h 
        ../src/swapnodesinpairs.cpp 
        swapnodesinpairs_test.cpp
    )
add_executable(swapnodesinpairs ${INCLUDED_FILES})
target_link_libraries(swapnodesinpairs gtest gmock_main)
cotire(swapnodesinpairs)
add_test(NAME swapnodesinpairs_test COMMAND swapnodesinpairs)
