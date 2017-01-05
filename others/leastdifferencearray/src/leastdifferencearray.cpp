/*
 * leastdifferencearray.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: songjiguo
 */

#include "leastdifferencearray.h"
#include <algorithm>
#include <climits>

int leastdifferencearray::leastdiffArray(vector<int> &nums)
{
	if(nums.size() == 1) return 0;

	std::sort(nums.begin(), nums.end());
	int min = INT_MAX;
	for(int i = 1; i < nums.size(); ++i) {
		min = std::min(std::abs(nums[i] - nums[i-1]), min);
	}

	return min;
}


