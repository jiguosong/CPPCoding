SET(INCLUDED_FILES
        ../src/wordsearch.h 
        ../src/wordsearch.cpp 
        wordsearch_test.cpp
    )
add_executable(wordsearch ${INCLUDED_FILES})
target_link_libraries(wordsearch gtest gmock_main)
cotire(wordsearch)
add_test(NAME wordsearch_test COMMAND wordsearch)
