SET(INCLUDED_FILES
        ../src/courseschedule.h 
        ../src/courseschedule.cpp 
        courseschedule_test.cpp
    )
add_executable(courseschedule ${INCLUDED_FILES})
target_link_libraries(courseschedule gtest gmock_main)
cotire(courseschedule)
add_test(NAME courseschedule_test COMMAND courseschedule)
