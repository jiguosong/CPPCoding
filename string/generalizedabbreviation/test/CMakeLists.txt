SET(INCLUDED_FILES
        ../src/generalizedabbreviation.h 
        ../src/generalizedabbreviation.cpp 
        generalizedabbreviation_test.cpp
    )
add_executable(generalizedabbreviation ${INCLUDED_FILES})
target_link_libraries(generalizedabbreviation gtest gmock_main)
cotire(generalizedabbreviation)
add_test(NAME generalizedabbreviation_test COMMAND generalizedabbreviation)
