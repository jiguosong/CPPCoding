SET(INCLUDED_FILES
        ../src/trappingwater.h 
        ../src/trappingwater.cpp 
        trappingwater_test.cpp
    )
add_executable(trappingwater ${INCLUDED_FILES})
target_link_libraries(trappingwater gtest gmock_main)
cotire(trappingwater)
add_test(NAME trappingwater_test COMMAND trappingwater)
