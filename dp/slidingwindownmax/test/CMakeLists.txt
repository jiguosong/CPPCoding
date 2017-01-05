SET(INCLUDED_FILES
        ../src/slidingwindownmax.h 
        ../src/slidingwindownmax.cpp 
        slidingwindownmax_test.cpp
    )
add_executable(slidingwindownmax ${INCLUDED_FILES})
target_link_libraries(slidingwindownmax gtest gmock_main)
cotire(slidingwindownmax)
add_test(NAME slidingwindownmax_test COMMAND slidingwindownmax)
