SET(INCLUDED_FILES
        ../src/movezerotoright.h 
        ../src/movezerotoright.cpp 
        movezerotoright_test.cpp
    )
add_executable(movezerotoright ${INCLUDED_FILES})
target_link_libraries(movezerotoright gtest gmock_main)
cotire(movezerotoright)
add_test(NAME movezerotoright_test COMMAND movezerotoright)
