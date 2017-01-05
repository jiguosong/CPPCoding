SET(INCLUDED_FILES
        ../src/longestnonrepsubstr.h 
        ../src/longestnonrepsubstr.cpp 
        longestnonrepsubstr_test.cpp
    )
add_executable(longestnonrepsubstr ${INCLUDED_FILES})
target_link_libraries(longestnonrepsubstr gtest gmock_main)
cotire(longestnonrepsubstr)
add_test(NAME longestnonrepsubstr_test COMMAND longestnonrepsubstr)
