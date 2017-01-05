SET(INCLUDED_FILES
        ../src/oneeditdistance.h 
        ../src/oneeditdistance.cpp 
        oneeditdistance_test.cpp
    )
add_executable(oneeditdistance ${INCLUDED_FILES})
target_link_libraries(oneeditdistance gtest gmock_main)
cotire(oneeditdistance)
add_test(NAME oneeditdistance_test COMMAND oneeditdistance)
