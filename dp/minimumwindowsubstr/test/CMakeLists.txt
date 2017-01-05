SET(INCLUDED_FILES
        ../src/minimumwindowsubstr.h 
        ../src/minimumwindowsubstr.cpp 
        minimumwindowsubstr_test.cpp
    )
add_executable(minimumwindowsubstr ${INCLUDED_FILES})
target_link_libraries(minimumwindowsubstr gtest gmock_main)
cotire(minimumwindowsubstr)
add_test(NAME minimumwindowsubstr_test COMMAND minimumwindowsubstr)
