SET(INCLUDED_FILES
        ../src/buildtreefrompreordernorder.h 
        ../src/buildtreefrompreordernorder.cpp 
        buildtreefrompreordernorder_test.cpp
    )
add_executable(buildtreefrompreordernorder ${INCLUDED_FILES})
target_link_libraries(buildtreefrompreordernorder gtest gmock_main)
cotire(buildtreefrompreordernorder)
add_test(NAME buildtreefrompreordernorder_test COMMAND buildtreefrompreordernorder)
