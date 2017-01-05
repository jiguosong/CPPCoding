/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <string>
#include "removekdigits.h"

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

TEST(removekdigits, normal1)
{
	removekdigits tc;
	std::string s = "1432219";
	int k = 3;
	ASSERT_EQ("1219", tc.removeKdigits(s, k));
}

TEST(removekdigits, zerocases)
{
	removekdigits tc;
	std::string s = "10200";
	int k = 1;
	ASSERT_EQ("200", tc.removeKdigits(s, k));
}

TEST(removekdigits, allremoved)
{
	removekdigits tc;
	std::string s = "10";
	int k = 2;
	ASSERT_EQ("0", tc.removeKdigits(s, k));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
