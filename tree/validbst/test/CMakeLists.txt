SET(INCLUDED_FILES
        ../src/validbst.h 
        ../src/validbst.cpp 
        validbst_test.cpp
    )
add_executable(validbst ${INCLUDED_FILES})
target_link_libraries(validbst gtest gmock_main)
cotire(validbst)
add_test(NAME validbst_test COMMAND validbst)
