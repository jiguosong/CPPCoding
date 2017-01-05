SET(INCLUDED_FILES
        ../src/meetingroom.h 
        ../src/meetingroom.cpp 
        meetingroom_test.cpp
    )
add_executable(meetingroom ${INCLUDED_FILES})
target_link_libraries(meetingroom gtest gmock_main)
cotire(meetingroom)
add_test(NAME meetingroom_test COMMAND meetingroom)
