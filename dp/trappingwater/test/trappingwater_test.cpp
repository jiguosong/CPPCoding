/*
 * trappingwater_test.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: songjiguo
 */

#include "../src/trappingwater.h"

#include "gtest/gtest.h"

#include <iostream>

using std::cout;
using std::endl;

TEST(testcase_OK1, trappingwater_maxArea)
{
	trappingwater c;
	vector<int> height = {9, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1};
	ASSERT_EQ(18, c.maxArea(height));
}

TEST(testcase_OK2, trappingwater_maxArea)
{
	trappingwater c;
	vector<int> height = {1, 2, 8, 9, 1, 1, 1, 1, 1, 1, 2};
	ASSERT_EQ(18, c.maxArea(height));
}

TEST(testcase_OK3, trappingwater_maxArea)
{
	trappingwater c;
	vector<int> height = {10};
	ASSERT_EQ(0, c.maxArea(height));
}

TEST(testcase_OK4, trappingwater_trap)
{
	trappingwater c;
	int height[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
	ASSERT_EQ(6, c.trap(height, 12));
}

TEST(testcase_OK5, trappingwater_trap)
{
	trappingwater c;
	int height[1] = {5};
	ASSERT_EQ(0, c.trap(height, 1));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	//::testing::GTEST_FLAG(filter) = "testcase_OK6";
	return RUN_ALL_TESTS();
}

