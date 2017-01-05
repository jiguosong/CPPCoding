/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>

#include "leastdifferencearray.h"

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

TEST(leastdifferencearray, normal)
{
	leastdifferencearray tc;
	vector<int> nums = {200,40,5,22,99,-2};

	ASSERT_EQ(7, tc.leastdiffArray(nums));
}

TEST(leastdifferencearray, one)
{
	leastdifferencearray tc;
	vector<int> nums = {2};

	ASSERT_EQ(0, tc.leastdiffArray(nums));
}

TEST(leastdifferencearray, pair)
{
	leastdifferencearray tc;
	vector<int> nums = {4,4};

	ASSERT_EQ(0, tc.leastdiffArray(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
