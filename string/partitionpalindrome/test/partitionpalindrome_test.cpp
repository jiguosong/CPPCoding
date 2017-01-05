/* googletest unit test for C++ */

#include "partitionpalindrome.h"
#include "gtest/gtest.h"
#include <iostream>
#include <set>

using std::cout; 
using std::endl;
using std::set;

TEST(testcase_OK1, partitionpalindrome)
{
	partitionpalindrome c;
	string s = "aab";
	vector<vector<string>> ans = c.partition_palindrome(s);

	set<vector<string>> set;
	for(vector<string> v : ans) set.insert(v);

	ASSERT_EQ(set.size(), ans.size());
	ASSERT_NE(set.find({"a", "a", "b"}), set.end());
	ASSERT_NE(set.find({"aa", "b"}), set.end());
}

TEST(testcase_OK2, partitionpalindrome)
{
	partitionpalindrome c;
	string s = "a";
	vector<vector<string>> ans = c.partition_palindrome(s);

	set<vector<string>> set;
	for(vector<string> v : ans) set.insert(v);

	ASSERT_EQ(set.size(), ans.size());
	ASSERT_NE(set.find({"a"}), set.end());
	ASSERT_EQ(set.find({"aa"}), set.end());
}

TEST(testcase_OK3, partitionpalindrome)
{
	partitionpalindrome c;
	string s = "aaaaaaaa";
	vector<vector<string>> ans = c.partition_palindrome(s);

	set<vector<string>> set;
	for(vector<string> v : ans) set.insert(v);

	ASSERT_EQ(set.size(), ans.size());
	ASSERT_NE(set.find({"a", "a","a","a","a","a","a","a"}), set.end());
	ASSERT_NE(set.find({"aa","aa","aa","aa"}), set.end());
	ASSERT_NE(set.find({"aaa","aaa","aa"}), set.end());
	ASSERT_NE(set.find({"aaaa","aaaa"}), set.end());
	ASSERT_NE(set.find({"aaaaa","aaa"}), set.end());
	ASSERT_NE(set.find({"aaaaaa","aa"}), set.end());
	ASSERT_NE(set.find({"aaaaaaa","a"}), set.end());
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
