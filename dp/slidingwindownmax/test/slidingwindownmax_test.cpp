/*
 * slidingwindownmax_test.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "slidingwindownmax.h"
#include "gtest/gtest.h"

#include <iostream>
TEST(testcase_OK1, slidingwindownmax)
{
	slidingwindownmax c;

	vector<int> nums= {1,3,-1,-3,5,3,6,7};
	int k = 3;
	vector<int> res = c.maxSlidingWindow(nums, k);
	vector<int> expected = {3,3,5,5,6,7};

	for(int i = 0; (size_t)i < res.size(); i++)
		ASSERT_EQ(res[i], expected[i]);
}

TEST(testcase_OK2, slidingwindownmax)
{
	slidingwindownmax c;

	vector<int> nums= {-7, -6, -5, -4, -3, -2, -1};
	int k = 3;
	vector<int> res = c.maxSlidingWindow(nums, k);
	vector<int> expected = {-5,-4,-3,-2,-1};

	for(int i = 0; (size_t)i < res.size(); i++)
		ASSERT_EQ(res[i], expected[i]);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
