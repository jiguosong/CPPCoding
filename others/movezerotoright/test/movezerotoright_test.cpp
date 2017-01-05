/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>

#include "../src/movezerotoright.h"

using std::cout; 
using std::endl;
using std::vector;

template<class T>
void PrintVector(const vector<T> &vec)
{
	for(size_t i = 0; i < vec.size(); ++i) cout << vec[i] << ' ';
	cout << endl;
}

template<class T>
void PrintVectorVector(const vector<vector<T>> &vec)
{
	for(size_t i = 0; i < vec.size(); ++i) PrintVector(vec[i]);
}

TEST(movezerotoright, normal)
{
	movezerotoright tc;
	vector<int> nums = {1,2,0,-2,0,3,5,0,1};
	tc.moveZeroesToRight(nums);
	PrintVector(nums);
	ASSERT_EQ(nums[0], 1);
	ASSERT_EQ(nums[1], 2);
	ASSERT_EQ(nums[2], 1);
	ASSERT_EQ(nums[3], -2);
	ASSERT_EQ(nums[4], 5);
	ASSERT_EQ(nums[5], 3);
	ASSERT_EQ(nums[6], 0);
	ASSERT_EQ(nums[7], 0);
	ASSERT_EQ(nums[8], 0);
}

TEST(movezerotoright, zeros)
{
	movezerotoright tc;
	vector<int> nums = {0,0,0};
	tc.moveZeroesToRight(nums);
	ASSERT_EQ(nums[0], 0);
	ASSERT_EQ(nums[1], 0);
	ASSERT_EQ(nums[2], 0);
}


TEST(movezerotoright, nonzeros)
{
	movezerotoright tc;
	vector<int> nums = {1,2,3};
	tc.moveZeroesToRight(nums);
	ASSERT_EQ(nums[0], 1);
	ASSERT_EQ(nums[1], 2);
	ASSERT_EQ(nums[2], 3);
}

TEST(movezerotoright, single)
{
	movezerotoright tc;
	vector<int> nums = {0};
	tc.moveZeroesToRight(nums);
	ASSERT_EQ(nums[0], 0);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
