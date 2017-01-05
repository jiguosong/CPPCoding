/*
 Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

 A region is captured by flipping all 'O's into 'X's in that surrounded region.

 For example,

 X X X X
 X O O X
 X X O X
 X O X X

 After running your function, the board should be:

 X X X X
 X X X X
 X X X X
 X O X X

 */

#include "surroundedregion.h"

#include <iostream>

using namespace std;

void surroundedregion::dummy() {
}

// from edge, turn all 'O' into '#', then flip back later
static void helper(vector<vector<char>> &board, int x, int y) {
    int row = board.size();
    int col = board[0].size();

    if (board[x][y] == 'O') {
        board[x][y] = '#';
    } else return;

    if (x > 0 && board[x - 1][y] == 'O')
        helper(board, x - 1, y);

    if (x < row - 1 && board[x + 1][y] == 'O')
        helper(board, x + 1, y);

    if (y > 0 && board[x][y - 1] == 'O')
        helper(board, x, y - 1);

    if (y < col - 1 && board[x][y + 1] == 'O')
        helper(board, x, y + 1);

}

void surroundedregion::solve(vector<vector<char>> &board) {
    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < row; ++i) {
        if (board[i][0] == 'O') {
            helper(board, i, 0);
        }
    }

    for (int i = 0; i < row; ++i) {
        if (board[i][col - 1] == 'O') {
            helper(board, i, col - 1);
        }
    }

    for (int i = 0; i < col; ++i) {
        if (board[0][i] == 'O') {
            helper(board, 0, i);
        }
    }

    for (int i = 0; i < col; ++i) {
        if (board[row - 1][i] == 'O') {
            helper(board, row - 1, i);
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}
