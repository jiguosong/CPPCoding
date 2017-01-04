SET(INCLUDED_FILES
        ../src/inordersuccessorbst.h 
        ../src/inordersuccessorbst.cpp 
        inordersuccessorbst_test.cpp
    )
add_executable(inordersuccessorbst ${INCLUDED_FILES})
target_link_libraries(inordersuccessorbst gtest gmock_main)
cotire(inordersuccessorbst)
add_test(NAME inordersuccessorbst_test COMMAND inordersuccessorbst)
