SET(INCLUDED_FILES
        ../src/removeNthNodefromend.h 
        ../src/removeNthNodefromend.cpp 
        removeNthNodefromend_test.cpp
    )
add_executable(removeNthNodefromend ${INCLUDED_FILES})
target_link_libraries(removeNthNodefromend gtest gmock_main)
cotire(removeNthNodefromend)
add_test(NAME removeNthNodefromend_test COMMAND removeNthNodefromend)
