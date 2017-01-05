SET(INCLUDED_FILES
        ../src/swapnodesKgroup.h 
        ../src/swapnodesKgroup.cpp 
        swapnodesKgroup_test.cpp
    )
add_executable(swapnodesKgroup ${INCLUDED_FILES})
target_link_libraries(swapnodesKgroup gtest gmock_main)
cotire(swapnodesKgroup)
add_test(NAME swapnodesKgroup_test COMMAND swapnodesKgroup)
