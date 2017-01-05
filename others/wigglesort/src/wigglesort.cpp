/*

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

 */

#include "wigglesort.h"

void wigglesort::dummy()
{
}

void wigglesort::wiggleSort(vector<int> &nums)
{
	for (int i = 1; i < nums.size(); ++i) {
		bool a = (i & 1 == 1) && nums[i] < nums[i - 1];
		bool b = (i & 1 == 0) && nums[i] > nums[i - 1];
		if (a || b)
			std::swap(nums[i], nums[i - 1]);
	}
}
