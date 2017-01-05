/*
 * permutation_test.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

#include "../src/permutation/permutation.h"
#include "gtest/gtest.h"
#include <iostream>
#include <set>
#include <algorithm>

using std::cout;
using std::endl;
using std::set;

TEST(testcase_OK1, permutation)
{
	permutation c;
	vector<int> nums = {1,2,3};
	vector<vector<int>> ans = c.permute(nums);

	//vector<int>::iterator it = find(list_vector.begin(), list_vector.end(), 5)
	ASSERT_EQ(ans.size(), 6);

	set<vector<int>> set;
	for(vector<int> v:ans) set.insert(v);

	ASSERT_EQ(set.size(), 6);
	ASSERT_NE(set.find({1,2,3}), set.end());
	ASSERT_NE(set.find({1,3,2}), set.end());
	ASSERT_NE(set.find({2,1,3}), set.end());
	ASSERT_NE(set.find({2,3,1}), set.end());
	ASSERT_NE(set.find({3,1,2}), set.end());
	ASSERT_NE(set.find({3,2,1}), set.end());
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
