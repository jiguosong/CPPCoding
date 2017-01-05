/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "longestpalindrome.h"

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
void PrintVectorVector(const vector<vector<T> > &vec)
{
	for(size_t i = 0; i < vec.size(); ++i) PrintVector(vec[i]);
}

TEST(longestpalindrome, normal)
{
	longestpalindrome tc;
	string s = "bananas";
	string ans = tc.longestPalindrome(s);

	ASSERT_EQ("anana", ans);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
