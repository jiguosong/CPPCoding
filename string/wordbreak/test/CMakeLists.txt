SET(INCLUDED_FILES
        ../src/wordbreak.h 
        ../src/wordbreak.cpp 
        wordbreak_test.cpp
    )
add_executable(wordbreak ${INCLUDED_FILES})
target_link_libraries(wordbreak gtest gmock_main)
cotire(wordbreak)
add_test(NAME wordbreak_test COMMAND wordbreak)
