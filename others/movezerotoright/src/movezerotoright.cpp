/*
 * movezerotoright.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: songjiguo
 */

#include "movezerotoright.h"

static void swap(vector<int> &nums, int i, int j)
{
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}

void movezerotoright::moveZeroesToRight(vector<int> &nums)
{
	int left = 0;
	int right = nums.size()-1;

	while(left < right) {
		while(nums[left] && left < nums.size()-1) ++left;
		while(!nums[right] && right > 0) --right;
		swap(nums, left, right);
		++left;
		--right;
	}
}
