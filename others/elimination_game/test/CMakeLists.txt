SET(INCLUDED_FILES
        ../src/elimination_game.h 
        ../src/elimination_game.cpp 
        elimination_game_test.cpp
    )
add_executable(elimination_game ${INCLUDED_FILES})
target_link_libraries(elimination_game gtest gmock_main)
cotire(elimination_game)
add_test(NAME elimination_game_test COMMAND elimination_game)
