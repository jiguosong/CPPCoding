/*
 * wordbreak_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "wordbreak.h"
#include "gtest/gtest.h"

TEST(testcase_OK1, wordbreak)
{
	solution c;
	string s = "leetcode";
	unordered_set<string> dict = {"leet", "code"};
	ASSERT_TRUE(c.wordBreak(s, dict));
}

TEST(testcase_OK2, wordbreak)
{
	solution c;
	string s = "aaaacodeaaa";
	unordered_set<string> dict = {"a", "code"};
	ASSERT_TRUE(c.wordBreak(s, dict));
}

TEST(testcase_Empty, wordbreak)
{
	solution c;
	string s = "";
	unordered_set<string> dict = {"a", "code"};
	ASSERT_FALSE(c.wordBreak(s, dict));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
