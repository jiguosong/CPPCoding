SET(INCLUDED_FILES
        ../src/trie.h 
        ../src/trie.cpp 
        trie_test.cpp
    )
add_executable(trie ${INCLUDED_FILES})
target_link_libraries(trie gtest gmock_main)
cotire(trie)
add_test(NAME trie_test COMMAND trie)
