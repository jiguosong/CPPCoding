/*
 * dividearray.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: songjiguo
 */

/*Partition an integer array in two parts such that sum of each parts are same. The elements need not to be contiguous.*/

#include "dividearray.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>

// contiguous
bool dividearray::isArrayDividableInEqualSums(vector<int> &nums)
{
	long long sum = 0;
	for(int i : nums) sum+= i;

	if(sum%2) return false;
	long long half = sum >> 1;
	sum = 0;
	for(int i : nums) {
		sum += i;
		if(sum == half) return true;
	}

	return false;
}

// not necessary contiguous (assume sum is not too big)
// Q: how about negative?
bool dividearray::isArrayDividableInEqualSums_Set(vector<int> &nums)
{
	long long sum = 0;
	vector<int> tmp_list;

	for(int i : nums) sum+= i;
	if(sum%2) return false;
	// sumlessthan(i,j) is the max sum from 0th to ith that the sum is no more than j
	vector<vector<int>> sumlessthan(nums.size()+1, vector<int>(abs(sum/2)+1, 0));

	for(int i = 1; i <= nums.size(); ++i) {
		for(int j = 1; j <= sum/2; ++j) {
			if(nums[i-1] > j) sumlessthan[i][j] = sumlessthan[i-1][j];
			else sumlessthan[i][j] = std::max(sumlessthan[i-1][j], nums[i-1] + sumlessthan[i-1][j - nums[i-1]]);
		}
	}
	return sumlessthan[nums.size()][sum/2] == sum/2;

}

vector<vector<int>> dividearray::allArrayDividableInEqualSums_Set(vector<int> &nums)
{
	long long sum = 0;
	vector<vector<int>> res;
	vector<int> tmp_list;

	for(int i : nums) {
		sum+= i;
		tmp_list.push_back(i);
	}
	if(sum%2) return res;
	// sumlessthan(i,j) is the max sum from 0th to ith that the sum is no more than j
	vector<vector<int>> sumlessthan(nums.size()+1, vector<int>(abs(sum/2)+1, 0));

	for(int i = 1; i <= nums.size(); ++i) {
		for(int j = 0; j <= sum/2; ++j) {
			if(nums[i-1] > j) sumlessthan[i][j] = sumlessthan[i-1][j];
			else sumlessthan[i][j] = std::max(sumlessthan[i-1][j], nums[i-1] + sumlessthan[i-1][j - nums[i-1]]);
		}
	}
	if (sumlessthan[nums.size()][sum/2] != sum/2) return res;

	int i = nums.size();
	int s = sum/2;
	vector<int> tmp_list2;
	while (s > 0 && i > 0) {
		if (nums[i - 1] <= s && sumlessthan[i][s] == nums[i - 1] + sumlessthan[i - 1][s - nums[i - 1]]) {
			tmp_list2.push_back(nums[i - 1]);
			s = s - nums[i - 1];
		}
		i--;
	}

	for(int e : tmp_list2) tmp_list.erase(std::remove(tmp_list.begin(), tmp_list.end(), e), tmp_list.end());

	res.push_back(tmp_list);
	res.push_back(tmp_list2);
	return res;
}



