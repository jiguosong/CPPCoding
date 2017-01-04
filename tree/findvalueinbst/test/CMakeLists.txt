SET(INCLUDED_FILES
        ../src/findvalueinbst.h 
        ../src/findvalueinbst.cpp 
        findvalueinbst_test.cpp
    )
add_executable(findvalueinbst ${INCLUDED_FILES})
target_link_libraries(findvalueinbst gtest gmock_main)
cotire(findvalueinbst)
add_test(NAME findvalueinbst_test COMMAND findvalueinbst)
