/*Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes
 * the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.*/

#include "minimumpathsum.h"

void minimumpathsum::dummy() 
{
}

int minimumpathsum::minPathSum(const vector<vector<int>> &matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();

	vector<vector<int>> dp(row, vector<int>(col, 0));
	dp[0][0] = matrix[0][0];
	for(int i = 1; i < row; ++i) dp[i][0] = dp[i-1][0] + matrix[i][0];
	for(int i = 1; i < col; ++i) dp[0][i] = dp[0][i-1] + matrix[0][i];

	for(int i = 1; i < row; ++i) {
		for(int j = 1; j < col; ++j) {
			dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
		}
	}

	return dp[row-1][col-1];
}
