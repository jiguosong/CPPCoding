SET(INCLUDED_FILES
        ../src/lcaBST.h 
        ../src/lcaBST.cpp 
        lcaBST_test.cpp
    )
add_executable(lcaBST ${INCLUDED_FILES})
target_link_libraries(lcaBST gtest gmock_main)
cotire(lcaBST)
add_test(NAME lcaBST_test COMMAND lcaBST)
