/*




 */

#include "nqueens.h"

void nqueens::dummy()
{
}

static bool isValidpos(vector<int> &pos, int row, int col)
{
	for (int i = 0; i < row; ++i) {
		if (pos[i] == col || std::abs(row - i) == std::abs(col - pos[i]))
			return false;
	}
	return true;
}

static void helper(vector<int> &pos, int level, vector<vector<string>> &res)
{
	int n = pos.size();
	if (level == n) {
		vector<string> s(n, string(n, '.'));
		for (int col = 0; col < n; ++col) {
			s[col][pos[col]] = 'Q';  // col is same as row
		}
		res.push_back(s);
		return;
	} else {
		for (int col = 0; col < n; ++col) {
			if (isValidpos(pos, level, col)) {
				pos[level] = col;
				helper(pos, level + 1, res);
				pos[level] = -1;
			}
		}
	}
}

vector<vector<string>> nqueens::solveNQueens(int n)
{
	vector<vector<string>> res;
	vector<int> pos(n, -1);

	helper(pos, 0, res);

	return res;
}
