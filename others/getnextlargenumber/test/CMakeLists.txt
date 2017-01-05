SET(INCLUDED_FILES
        ../src/getnextlargenumber.h 
        ../src/getnextlargenumber.cpp 
        getnextlargenumber_test.cpp
    )
add_executable(getnextlargenumber ${INCLUDED_FILES})
target_link_libraries(getnextlargenumber gtest gmock_main)
cotire(getnextlargenumber)
add_test(NAME getnextlargenumber_test COMMAND getnextlargenumber)
