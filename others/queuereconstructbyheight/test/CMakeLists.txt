SET(INCLUDED_FILES
        ../src/queuereconstructbyheight.h 
        ../src/queuereconstructbyheight.cpp 
        queuereconstructbyheight_test.cpp
    )
add_executable(queuereconstructbyheight ${INCLUDED_FILES})
target_link_libraries(queuereconstructbyheight gtest gmock_main)
cotire(queuereconstructbyheight)
add_test(NAME queuereconstructbyheight_test COMMAND queuereconstructbyheight)
