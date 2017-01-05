/*
 * rotatearray.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

#include "rotatearray.h"

static void revserse(vector<int> &nums, int left, int right)
{
	while(left < right) {
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		++left;
		--right;
	}
}

void rotatearray::rotate(vector<int> &nums, int k)
{
	if(k <= 0 || nums.empty()) return;
	k = k%nums.size();

	revserse(nums, 0, nums.size() - k - 1);
	revserse(nums, nums.size()-k, nums.size() - 1);
	revserse(nums, 0, nums.size() - 1);
}
