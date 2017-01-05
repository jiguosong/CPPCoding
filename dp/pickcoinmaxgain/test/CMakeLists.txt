SET(INCLUDED_FILES
        ../src/pickcoinmaxgain.h 
        ../src/pickcoinmaxgain.cpp 
        pickcoinmaxgain_test.cpp
    )
add_executable(pickcoinmaxgain ${INCLUDED_FILES})
target_link_libraries(pickcoinmaxgain gtest gmock_main)
cotire(pickcoinmaxgain)
add_test(NAME pickcoinmaxgain_test COMMAND pickcoinmaxgain)
