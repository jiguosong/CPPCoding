/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 Example 1:

 11110
 11010
 11000
 00000

 Answer: 1

 Example 2:

 11000
 11000
 00100
 00011

 Answer: 3
 */

#include "numberofislands.h"

void numberofislands::dummy()
{
}

static void numIslands_helper(vector<vector<char> > &grid, int i, int j,
		vector<vector<bool> > &visited)
{
	if (i < 0 || i >= grid.size())
		return;
	if (j < 0 || j >= grid[0].size())
		return;
	if (grid[i][j] != '1' || visited[i][j] == true)
		return;

	visited[i][j] = true;

	numIslands_helper(grid, i, j - 1, visited);
	numIslands_helper(grid, i, j + 1, visited);
	numIslands_helper(grid, i - 1, j, visited);
	numIslands_helper(grid, i + 1, j, visited);

}

int numberofislands::numIslands(vector<vector<char> > &grid)
{
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<bool>> visited(row, vector<bool>(col, false));

	int ans = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (grid[i][j] == '1' && visited[i][j] == false) {
				numIslands_helper(grid, i, j, visited);
				++ans;
			}
		}
	}

	return ans;
}
