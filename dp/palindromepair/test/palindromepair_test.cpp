/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "palindromepair.h"

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

TEST(palindromepair, normal)
{
	palindromepair tc;
	vector<string> words = {"bat", "tab", "cat"};
	vector<vector<int>> ans = tc.palindromePairs(words);

	ASSERT_EQ(ans[0][0], 0);
	ASSERT_EQ(ans[0][1], 1);
	ASSERT_EQ(ans[1][0], 1);
	ASSERT_EQ(ans[1][1], 0);
}

TEST(palindromepair, normal2)
{
	palindromepair tc;
	vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
	vector<vector<int>> ans = tc.palindromePairs(words);

	ASSERT_EQ(ans[0][0], 0);
	ASSERT_EQ(ans[0][1], 1);
	ASSERT_EQ(ans[1][0], 1);
	ASSERT_EQ(ans[1][1], 0);
	ASSERT_EQ(ans[2][0], 3);
	ASSERT_EQ(ans[2][1], 2);
	ASSERT_EQ(ans[3][0], 2);
	ASSERT_EQ(ans[3][1], 4);
}

TEST(palindromepair, empty)
{
	palindromepair tc;
	vector<string> words = {""};
	vector<vector<int>> ans = tc.palindromePairs(words);

	ASSERT_TRUE(ans.empty());
}


TEST(palindromepair, oneempty)
{
	palindromepair tc;
	vector<string> words = {"", "a"};
	vector<vector<int>> ans = tc.palindromePairs(words);

	ASSERT_EQ(ans[0][0], 1);
	ASSERT_EQ(ans[0][1], 0);
	ASSERT_EQ(ans[1][0], 0);
	ASSERT_EQ(ans[1][1], 1);

}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
