SET(INCLUDED_FILES
        ../src/wordladder.h 
        ../src/wordladder.cpp 
        wordladder_test.cpp
    )
add_executable(wordladder ${INCLUDED_FILES})
target_link_libraries(wordladder gtest gmock_main)
cotire(wordladder)
add_test(NAME wordladder_test COMMAND wordladder)
