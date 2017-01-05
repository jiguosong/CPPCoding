SET(INCLUDED_FILES
        ../src/containduplicate.h 
        ../src/containduplicate.cpp 
        containduplicate_test.cpp
    )
add_executable(containduplicate ${INCLUDED_FILES})
target_link_libraries(containduplicate gtest gmock_main)
cotire(containduplicate)
add_test(NAME containduplicate_test COMMAND containduplicate)
