SET(INCLUDED_FILES
        ../src/serializedeserializeBT.h 
        ../src/serializedeserializeBT.cpp 
        serializedeserializeBT_test.cpp
    )
add_executable(serializedeserializeBT ${INCLUDED_FILES})
target_link_libraries(serializedeserializeBT gtest gmock_main)
cotire(serializedeserializeBT)
add_test(NAME serializedeserializeBT_test COMMAND serializedeserializeBT)
