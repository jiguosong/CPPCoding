SET(INCLUDED_FILES
        ../src/buysellstock2.h 
        ../src/buysellstock2.cpp 
        buysellstock2_test.cpp
    )
add_executable(buysellstock2 ${INCLUDED_FILES})
target_link_libraries(buysellstock2 gtest gmock_main)
cotire(buysellstock2)
add_test(NAME buysellstock2_test COMMAND buysellstock2)
