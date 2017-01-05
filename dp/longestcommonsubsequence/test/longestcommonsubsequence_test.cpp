/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "longestcommonsubsequence.h"

using std::cout; 
using std::endl;
using std::vector;

/*
   Choose auto x when you want to work with copies.
   Choose auto &x when you want to work with original items and may modify them.
   Choose auto const &x when you want to work with original items and will not modify them 
*/
template<class T>
void PrintVector(const vector<T> &vec)
{
	for(auto const &v:vec) cout << v << ' ';
	cout << endl;
}

template<class T>
void PrintVectorVector(const vector<vector<T>> &vec)
{
	for(auto const &v:vec) PrintVector(v);
}

TEST(longestcommonsubsequence, normal0)
{
	longestcommonsubsequence tc;

	string a = "abcdgh";
	string b = "awbc";
	ASSERT_EQ(3, tc.getLongestCommonSubsequence(a, b));
}

TEST(longestcommonsubsequence, normal)
{
	longestcommonsubsequence tc;

	string a = "abcdgh";
	string b = "aedfhr";
	ASSERT_EQ(3, tc.getLongestCommonSubsequence(a, b));
}

TEST(longestcommonsubsequence, normal2)
{
	longestcommonsubsequence tc;

	string a = "AGGTAB";
	string b = "GXTXAYB";
	ASSERT_EQ(4, tc.getLongestCommonSubsequence(a, b));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
