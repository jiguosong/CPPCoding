/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>

#include "minimumwindowsubstr.h"

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

TEST(minimumwindowsubstr, normal)
{
	minimumwindowsubstr tc;
	string s = "ADOBECODEBANC";
	string t = "ABC";
	ASSERT_EQ("BANC", tc.minWindow(s, t));
}

TEST(minimumwindowsubstr, notcontain)
{
	minimumwindowsubstr tc;
	string s = "ADOBECODEBANC";
	string t = "ZYZ";
	ASSERT_EQ("", tc.minWindow(s, t));
}

TEST(minimumwindowsubstr, cornercase)
{
	minimumwindowsubstr tc;
	string s = "AABBCC";
	string t = "ABC";
	ASSERT_EQ("ABBC", tc.minWindow(s, t));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
