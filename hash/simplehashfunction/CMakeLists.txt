SET(INCLUDED_FILES
        simplehashfunction.h 
        simplehashfunction.cpp 
        simplehashfunction_test.cpp
    )
add_executable(simplehashfunction ${INCLUDED_FILES})
target_link_libraries(simplehashfunction gtest gmock_main)
cotire(simplehashfunction)
add_test(NAME simplehashfunction_test COMMAND simplehashfunction)
