SET(INCLUDED_FILES
        ../src/findstreammedian.h 
        ../src/findstreammedian.cpp 
        findstreammedian_test.cpp
    )
add_executable(findstreammedian ${INCLUDED_FILES})
target_link_libraries(findstreammedian gtest gmock_main)
cotire(findstreammedian)
add_test(NAME findstreammedian_test COMMAND findstreammedian)
