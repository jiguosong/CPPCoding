SET(INCLUDED_FILES
        ../src/linkedlistcycle.h 
        ../src/linkedlistcycle.cpp 
        linkedlistcycle_test.cpp
    )
add_executable(linkedlistcycle ${INCLUDED_FILES})
target_link_libraries(linkedlistcycle gtest gmock_main)
cotire(linkedlistcycle)
add_test(NAME linkedlistcycle_test COMMAND linkedlistcycle)
