SET(INCLUDED_FILES
        ../src/buildtreefrompostordernorder.h 
        ../src/buildtreefrompostordernorder.cpp 
        buildtreefrompostordernorder_test.cpp
    )
add_executable(buildtreefrompostordernorder ${INCLUDED_FILES})
target_link_libraries(buildtreefrompostordernorder gtest gmock_main)
cotire(buildtreefrompostordernorder)
add_test(NAME buildtreefrompostordernorder_test COMMAND buildtreefrompostordernorder)
