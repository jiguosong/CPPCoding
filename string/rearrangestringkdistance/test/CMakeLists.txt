SET(INCLUDED_FILES
        ../src/rearrangestringkdistance.h 
        ../src/rearrangestringkdistance.cpp 
        rearrangestringkdistance_test.cpp
    )
add_executable(rearrangestringkdistance ${INCLUDED_FILES})
target_link_libraries(rearrangestringkdistance gtest gmock_main)
cotire(rearrangestringkdistance)
add_test(NAME rearrangestringkdistance_test COMMAND rearrangestringkdistance)
