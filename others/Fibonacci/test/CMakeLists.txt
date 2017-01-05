SET(INCLUDED_FILES
        ../src/Fibonacci.h 
        ../src/Fibonacci.cpp 
        Fibonacci_test.cpp
    )
add_executable(Fibonacci ${INCLUDED_FILES})
target_link_libraries(Fibonacci gtest gmock_main)
cotire(Fibonacci)
add_test(NAME Fibonacci_test COMMAND Fibonacci)
