SET(INCLUDED_FILES
        ../src/resorvoirsampling.h 
        ../src/resorvoirsampling.cpp 
        resorvoirsampling_test.cpp
    )
add_executable(resorvoirsampling ${INCLUDED_FILES})
target_link_libraries(resorvoirsampling gtest gmock_main)
cotire(resorvoirsampling)
add_test(NAME resorvoirsampling_test COMMAND resorvoirsampling)
