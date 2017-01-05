#include "permutation.h"
#include <string>

/*Given a collection of numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].*/

static void permute_helper(vector<int> &nums, int level, vector<bool> &visited,
		vector<int> &tmp, vector<vector<int>> &res)
{
	if (tmp.size() == nums.size()) {
		res.push_back(tmp);
		return;
	}

	for (int i = 0; (size_t) i < nums.size(); i++) {
		if (visited[i] == true)
			continue;

		visited[i] = true;
		tmp.push_back(nums[i]);
		permute_helper(nums, i + 1, visited, tmp, res);
		visited[i] = false;
		tmp.pop_back();
	}
	return;
}

vector<vector<int>> permutation::permute(vector<int> &nums)
{
	vector<vector<int>> res;
	vector<int> tmp;
	vector<bool> visited(nums.size(), false);

	permute_helper(nums, 0, visited, tmp, res);

	return res;
}
