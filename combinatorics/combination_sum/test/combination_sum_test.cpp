/*
 * combination_sum_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "gtest/gtest.h"
#include "../src/combination_sum/combination_sum.h"

#include <iostream>
using namespace std;

TEST(testcase_OK, combination_sum)
{
	solution test;

	vector<int> candidates = {2,3,6,7};
	int target = 7;
	vector<vector<int>> res = test.combinationSum(candidates, target);
	vector<vector<int>> expected  = {{7}, {2, 2, 3}};

	std::sort(res.begin(), res.end());
	std::sort(expected.begin(), expected.end());

	for(unsigned int i = 0; i < res.size(); i++) {
		vector<int> t1 = res[i];
		vector<int> t2 = expected[i];
		EXPECT_EQ(t1, t2);
	}
}

TEST(testcase_OK2, combination_sum)
{
	solution test;

	vector<int> candidates = {2,3,6,7};
	int target = 9;
	vector<vector<int>> res = test.combinationSum(candidates, target);
	vector<vector<int>> expected  = {{3,6}, {7,2}, {2,2,2,3}, {3,3,3}};

	std::sort(res.begin(), res.end());
	std::sort(expected.begin(), expected.end());

	for(unsigned int i = 0; i < res.size(); i++) {
		vector<int> t1 = res[i];
		//vector<int> t2 = expected[i];
		//EXPECT_EQ(t1, t2);
	}
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}





