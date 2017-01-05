/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.

 For example,

 Consider the following matrix:

 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]

 Given target = 3, return true.
 */

#include "search2dmatrix.h"

void search2dmatrix::dummy()
{
}

/*

  2D indexes  -> 1D index
  i*row+j => Idx

  1D index  -> 2D indexes
  Idx/row => i
  Idx%row => j
*/

bool search2dmatrix::searchMatrix(vector<vector<int> > &matrix, int target)
{
	int row = matrix.size();
	int col = matrix[0].size();

	int left = 0;
	int right = row * col - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (matrix[mid / row][mid % row] == target) {
			return true;
		} else if (matrix[mid / row][mid % row] < target) {
			left = mid+1;
		} else {
			right = mid-1;
		}
	}

	return false;
}
