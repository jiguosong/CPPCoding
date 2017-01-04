SET(INCLUDED_FILES
        ../src/lcaBT.h 
        ../src/lcaBT.cpp 
        lcaBT_test.cpp
    )
add_executable(lcaBT ${INCLUDED_FILES})
target_link_libraries(lcaBT gtest gmock_main)
cotire(lcaBT)
add_test(NAME lcaBT_test COMMAND lcaBT)
