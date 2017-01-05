SET(INCLUDED_FILES
        ../src/removeduplicats.h 
        ../src/removeduplicats.cpp 
        removeduplicats_test.cpp
    )
add_executable(removeduplicats ${INCLUDED_FILES})
target_link_libraries(removeduplicats gtest gmock_main)
cotire(removeduplicats)
add_test(NAME removeduplicats_test COMMAND removeduplicats)
