SET(INCLUDED_FILES
        ../src/editdistance.h 
        ../src/editdistance.cpp 
        editdistance_test.cpp
    )
add_executable(editdistance ${INCLUDED_FILES})
target_link_libraries(editdistance gtest gmock_main)
cotire(editdistance)
add_test(NAME editdistance_test COMMAND editdistance)
