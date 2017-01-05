SET(INCLUDED_FILES
        ../src/painthouses.h 
        ../src/painthouses.cpp 
        painthouses_test.cpp
    )
add_executable(painthouses ${INCLUDED_FILES})
target_link_libraries(painthouses gtest gmock_main)
cotire(painthouses)
add_test(NAME painthouses_test COMMAND painthouses)
