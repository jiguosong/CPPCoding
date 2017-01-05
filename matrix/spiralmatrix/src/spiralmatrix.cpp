/*

 Given a matrix of m x n elements (m rows, n columns), return all elements
 of the matrix in spiral order.

 For example,
 Given the following matrix:

 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]

 You should return [1,2,3,6,9,8,7,4,5].

 */

#include "spiralmatrix.h"

void spiralmatrix::dummy()
{
}

#include <iostream>
using namespace std;

static void helper(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2,
		vector<int> &res)
{
	if (x2 < 0 || y2 < 0 || x1 >= matrix.size() || y1 >= matrix[0].size())
		return;
	if (x1 > x2 || y1 > y2)
		return;

	for (int i = y1; i <= y2; ++i)
		res.push_back(matrix[x1][i]);

	if (x1 == x2)
		return;
	for (int i = x1 + 1; i <= x2; ++i)
		res.push_back(matrix[i][y2]);

	if (y1 == y2)
		return;
	for (int i = y2 - 1; i >= y1; --i)
		res.push_back(matrix[x2][i]);

	if (x1 == x2)
		return;
	for (int i = x2 - 1; i >= x1 + 1; --i)
		res.push_back(matrix[i][y1]);

	helper(matrix, x1 + 1, y1 + 1, x2 - 1, y2 - 1, res);

}

vector<int> spiralmatrix::printSpiralMatrix(vector<vector<int>> &matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> res;
	helper(matrix, 0, 0, row - 1, col - 1, res);
	return res;
}
