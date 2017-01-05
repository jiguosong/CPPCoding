#include "leftmostsmallernumber.h"
#include <limits>

void leftmostsmallernumber::dummy()
{
}

vector<int> leftmostsmallernumber::LeftSmallerNums(
		const vector<unsigned int> nums, unsigned int m)
{
	const int max_int = std::numeric_limits<int>::max();
	unsigned int sz = nums.size();

	vector<unsigned int> arr(m+1, max_int);
	vector<int> res(sz, 0);

	for (unsigned int i = 0; i < sz; ++i) {
		arr[nums[i]] = std::min(arr[nums[i]], i);
	}

	for (unsigned int i = 1; i < m; ++i) {
		arr[i] = std::min(arr[i], arr[i - 1]);
	}

	for (unsigned int i = 0; i < sz; ++i) {
		int idx = nums[i] - 1;
		if(arr[idx] > i) res[i] = -1;
		else res[i] = nums[arr[idx]];
	}

	return res;
}
