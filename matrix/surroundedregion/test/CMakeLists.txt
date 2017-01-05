SET(INCLUDED_FILES
        ../src/surroundedregion.h 
        ../src/surroundedregion.cpp 
        surroundedregion_test.cpp
    )
add_executable(surroundedregion ${INCLUDED_FILES})
target_link_libraries(surroundedregion gtest gmock_main)
cotire(surroundedregion)
add_test(NAME surroundedregion_test COMMAND surroundedregion)
