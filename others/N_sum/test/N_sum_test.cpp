/*
 * N_sum_test.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#include "N_sum.h"
#include "gtest/gtest.h"

TEST(testcase_OK1, 2sum)
{
	N_sum c;
	vector<int> input {0, 1, 2, 3, 4, 5, 6};
	int target = 9;
	vector<int> res = c.twoSum(input, target);
	vector<int> expected = {5,4};
	for(int i = 0; (size_t)i < res.size(); i++) ASSERT_EQ(res[i], expected[i]);
}

TEST(testcase_OK2, 3sum)
{
	N_sum c;
	vector<int> input {1,2,-3,4,5};
	vector<vector<int>> res = c.threeSum(input);
	vector<vector<int>> expected = {{-3, 1, 2}};
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



