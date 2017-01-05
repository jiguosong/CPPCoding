SET(INCLUDED_FILES
        ../src/median_datastream.h 
        ../src/median_datastream.cpp 
        median_datastream_test.cpp
    )
add_executable(median_datastream ${INCLUDED_FILES})
target_link_libraries(median_datastream gtest gmock_main)
cotire(median_datastream)
add_test(NAME median_datastream_test COMMAND median_datastream)
