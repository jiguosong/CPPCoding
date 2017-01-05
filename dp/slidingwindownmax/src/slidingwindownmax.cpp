/*
 * slidingwindownmax.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "slidingwindownmax.h"

#include <string>
#include <deque>
using std::deque;

/*
 *         ________________i
 *        |                |
 *   front|      sz=k      |  back
 *   ******************************
 *
 */

vector<int> slidingwindownmax:: maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> res;
	deque<int> dq;
	if(k <= 0) return res;

	for(int i = 0; (size_t)i < nums.size(); ++i) {
		if(!dq.empty() && (i - dq.front()) == k) dq.pop_front();
		while(!dq.empty() && (nums[dq.back()] < nums[i])) dq.pop_back();
		dq.push_back(i);
		if(i >= k - 1) res.push_back(nums[dq.front()]);
	}

	return res;
}
