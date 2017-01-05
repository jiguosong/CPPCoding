SET(INCLUDED_FILES
        ../src/buysellstock.h 
        ../src/buysellstock.cpp 
        buysellstock_test.cpp
    )
add_executable(buysellstock ${INCLUDED_FILES})
target_link_libraries(buysellstock gtest gmock_main)
cotire(buysellstock)
add_test(NAME buysellstock_test COMMAND buysellstock)
