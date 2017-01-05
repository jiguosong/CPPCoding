/* googletest unit test for C++ */

#include "rotatearray.h"
#include "gtest/gtest.h"
#include <iostream>

using std::cout; 
using std::endl;

TEST(testcase_OK1, rotatearray)
{
	rotatearray c;
	vector<int> nums = {1,2,3,4,5,6};
	int k = 2;
	c.rotate(nums, k);
	vector<int> expected = {5,6,1,2,3,4};

	for(int i = 0; (size_t)i < nums.size(); ++i) {
		ASSERT_EQ(expected[i], nums[i]);
	}
}

TEST(testcase_OK2, rotatearray)
{
	rotatearray c;
	vector<int> nums = {};
	int k = 2;
	c.rotate(nums, k);
	vector<int> expected = {};

	for(int i = 0; (size_t)i < nums.size(); ++i) {
		ASSERT_EQ(expected[i], nums[i]);
	}
}

TEST(testcase_OK3, rotatearray)
{
	rotatearray c;
	vector<int> nums = {1,2,3,4,5,6};
	int k = 20;
	c.rotate(nums, k);
	vector<int> expected = {5,6,1,2,3,4};

	for(int i = 0; (size_t)i < nums.size(); ++i) {
		ASSERT_EQ(expected[i], nums[i]);
	}
}

TEST(testcase_OK4, rotatearray)
{
	rotatearray c;
	vector<int> nums = {1,2,3,4,5,6};
	int k = -5;
	c.rotate(nums, k);
	vector<int> expected = {1,2,3,4,5,6};

	for(int i = 0; (size_t)i < nums.size(); ++i) {
		ASSERT_EQ(expected[i], nums[i]);
	}
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
