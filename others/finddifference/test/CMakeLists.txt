SET(INCLUDED_FILES
        ../src/finddifference.h 
        ../src/finddifference.cpp 
        finddifference_test.cpp
    )
add_executable(finddifference ${INCLUDED_FILES})
target_link_libraries(finddifference gtest gmock_main)
cotire(finddifference)
add_test(NAME finddifference_test COMMAND finddifference)
