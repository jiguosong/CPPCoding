/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>

#include "getnextlargenumber.h"

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

TEST(getnextlargenumber, normal)
{
	getnextlargenumber tc;
	int num = 123;
	ASSERT_EQ(tc.getNextLarger(num), 132);
}


TEST(getnextlargenumber, normal2)
{
	getnextlargenumber tc;
	int num = 3784;
	ASSERT_EQ(tc.getNextLarger(num), 3847);
}

TEST(getnextlargenumber, singledigit)
{
	getnextlargenumber tc;
	int num = 1;
	ASSERT_EQ(tc.getNextLarger(num), 1);
}

TEST(getnextlargenumber, zero)
{
	getnextlargenumber tc;
	int num = 0;
	ASSERT_EQ(tc.getNextLarger(num), 0);
}


TEST(getnextlargenumber, negative)
{
	getnextlargenumber tc;
	int num = -321;
	ASSERT_EQ(tc.getNextLarger(num), -312);
}

TEST(getnextlargenumber, negative2)
{
	getnextlargenumber tc;
	int num = -203465;
	ASSERT_EQ(tc.getNextLarger(num), -203456);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
