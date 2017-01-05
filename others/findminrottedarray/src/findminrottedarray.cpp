/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.*/

#include "findminrottedarray.h"

void findminrottedarray::dummy() 
{
}

int findminrottedarray::findMinRotArray(vector<int> &nums)
{
	if(nums.front() < nums.back()) return nums.front();

	int left = 0;
	int right = nums.size()-1;
	int res = 0;
	while(left < right - 1) {
		int mid = left + (right - left)/2;
		if(nums[left] < nums[mid]) left = mid;
		else right = mid;
	}

	res = std::min(nums[left], nums[right]);
	return res;
}
