SET(INCLUDED_FILES
        ../src/productrest.h 
        ../src/productrest.cpp 
        productrest_test.cpp
    )
add_executable(productrest ${INCLUDED_FILES})
target_link_libraries(productrest gtest gmock_main)
cotire(productrest)
add_test(NAME productrest_test COMMAND productrest)
