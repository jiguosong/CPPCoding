SET(INCLUDED_FILES
        ../src/countersmallernumberafterself.h 
        ../src/countersmallernumberafterself.cpp 
        countersmallernumberafterself_test.cpp
    )
add_executable(countersmallernumberafterself ${INCLUDED_FILES})
target_link_libraries(countersmallernumberafterself gtest gmock_main)
cotire(countersmallernumberafterself)
add_test(NAME countersmallernumberafterself_test COMMAND countersmallernumberafterself)
