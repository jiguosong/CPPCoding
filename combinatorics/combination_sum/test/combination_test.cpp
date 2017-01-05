/*
 * combination_test.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

#include "../src/combination/combination.h"

#include "gtest/gtest.h"
#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

TEST(combination, normal)
{
	combination c;
	vector<vector<int>> ans = c.combine(4,2);

	ASSERT_EQ(6, ans.size());
	set<vector<int>> set;
	for(vector<int> v:ans) set.insert(v);
	ASSERT_EQ(6, set.size());
	ASSERT_NE(set.find({1,2}), set.end());
	ASSERT_NE(set.find({1,3}), set.end());
	ASSERT_NE(set.find({1,4}), set.end());
	ASSERT_NE(set.find({2,3}), set.end());
	ASSERT_NE(set.find({2,4}), set.end());
	ASSERT_NE(set.find({3,4}), set.end());
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


