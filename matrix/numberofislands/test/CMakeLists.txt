SET(INCLUDED_FILES
        ../src/numberofislands.h 
        ../src/numberofislands.cpp 
        numberofislands_test.cpp
    )
add_executable(numberofislands ${INCLUDED_FILES})
target_link_libraries(numberofislands gtest gmock_main)
cotire(numberofislands)
add_test(NAME numberofislands_test COMMAND numberofislands)
