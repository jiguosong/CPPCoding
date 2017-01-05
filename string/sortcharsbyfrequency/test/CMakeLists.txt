SET(INCLUDED_FILES
        ../src/sortcharsbyfrequency.h 
        ../src/sortcharsbyfrequency.cpp 
        sortcharsbyfrequency_test.cpp
    )
add_executable(sortcharsbyfrequency ${INCLUDED_FILES})
target_link_libraries(sortcharsbyfrequency gtest gmock_main)
cotire(sortcharsbyfrequency)
add_test(NAME sortcharsbyfrequency_test COMMAND sortcharsbyfrequency)
