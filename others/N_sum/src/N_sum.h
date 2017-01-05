/*
 * N_sum.h
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#ifndef N_SUM_H_
#define N_SUM_H_

#include <vector>

using std::vector;

class N_sum {
public:
	vector<int> twoSum(vector<int> &nums, int target);
	vector<vector<int>> threeSum(vector<int>& nums);
};



#endif /* N_SUM_H_ */
