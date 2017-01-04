SET(INCLUDED_FILES
        ../src/palindromepermutation.h 
        ../src/palindromepermutation.cpp 
        palindromepermutation_test.cpp
    )
add_executable(palindromepermutation ${INCLUDED_FILES})
target_link_libraries(palindromepermutation gtest gmock_main)
cotire(palindromepermutation)
add_test(NAME palindromepermutation_test COMMAND palindromepermutation)
