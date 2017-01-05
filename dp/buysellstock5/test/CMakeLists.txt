SET(INCLUDED_FILES
        ../src/buysellstock5.h 
        ../src/buysellstock5.cpp 
        buysellstock5_test.cpp
    )
add_executable(buysellstock5 ${INCLUDED_FILES})
target_link_libraries(buysellstock5 gtest gmock_main)
cotire(buysellstock5)
add_test(NAME buysellstock5_test COMMAND buysellstock5)
