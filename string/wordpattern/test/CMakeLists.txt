SET(INCLUDED_FILES
        ../src/wordpattern.h 
        ../src/wordpattern.cpp 
        wordpattern_test.cpp
    )
add_executable(wordpattern ${INCLUDED_FILES})
target_link_libraries(wordpattern gtest gmock_main)
cotire(wordpattern)
add_test(NAME wordpattern_test COMMAND wordpattern)
