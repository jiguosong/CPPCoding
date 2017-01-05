SET(INCLUDED_FILES
        ../src/movezerotoright_keeporder.h 
        ../src/movezerotoright_keeporder.cpp 
        movezerotoright_keeporder_test.cpp
    )
add_executable(movezerotoright_keeporder ${INCLUDED_FILES})
target_link_libraries(movezerotoright_keeporder gtest gmock_main)
cotire(movezerotoright_keeporder)
add_test(NAME movezerotoright_keeporder_test COMMAND movezerotoright_keeporder)
