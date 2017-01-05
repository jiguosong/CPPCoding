SET(INCLUDED_FILES
        ../src/buysellstock3.h 
        ../src/buysellstock3.cpp 
        buysellstock3_test.cpp
    )
add_executable(buysellstock3 ${INCLUDED_FILES})
target_link_libraries(buysellstock3 gtest gmock_main)
cotire(buysellstock3)
add_test(NAME buysellstock3_test COMMAND buysellstock3)
