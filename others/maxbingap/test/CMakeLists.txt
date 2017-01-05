SET(INCLUDED_FILES
        ../src/maxbingap.h 
        ../src/maxbingap.cpp 
        maxbingap_test.cpp
    )
add_executable(maxbingap ${INCLUDED_FILES})
target_link_libraries(maxbingap gtest gmock_main)
cotire(maxbingap)
add_test(NAME maxbingap_test COMMAND maxbingap)
