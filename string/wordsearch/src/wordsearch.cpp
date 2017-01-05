/*
 * wordsearch.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "wordsearch.h"

using std::vector;

static bool exist_helper(vector<vector<char>> &board, std::string word, int level, int i, int j, vector<vector<bool>> &visisted);

bool solution::exist(vector<vector<char>> &board, std::string word)
{
	if(word.empty()) return false;
	if(board.empty() || board[0].empty()) return false;

	vector<vector<bool>> visisted (board.size(), vector<bool>(board[0].size(), false));

	int m = board.size();
	int n = board[0].size();

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			bool res = exist_helper(board, word, 0, i, j, visisted);
			if (res == true) return true;
		}
	}
	return false;
}

static bool exist_helper(vector<vector<char>> &board, std::string word, int level, int i, int j, vector<vector<bool>> &visisted)
{
	if((size_t)level == word.size()) return true;
	if(i < 0 || (size_t)i >= board.size() || j < 0 || (size_t)j > board[0].size()) return false;
	if(visisted[i][j]) return false;
	if(board[i][j] != word[level]) return false;

	visisted[i][j] = true;
	bool ans = exist_helper(board, word, level+1, i-1, j, visisted) ||
				exist_helper(board, word, level+1, i+1, j, visisted) ||
				exist_helper(board, word, level+1, i, j+1, visisted) ||
				exist_helper(board, word, level+1, i, j-1, visisted);
	visisted[i][j] = false;
	return ans;
}
