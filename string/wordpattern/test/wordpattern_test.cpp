/*
 * wordpattern_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "gtest/gtest.h"
#include "wordpattern.h"

TEST(testcase_OK1, wordpattern)
{
	solution c;
	std::string pattern = "abba";
	std::string str = "dog cat cat dog";
	EXPECT_TRUE(c.wordPattern(pattern, str));
}

TEST(testcase_OK2, wordpattern)
{
	solution c;
	std::string pattern = "abba";
	std::string str = "dog cat cat fish";
	EXPECT_FALSE(c.wordPattern(pattern, str));
}

TEST(testcase_OK3, wordpattern)
{
	solution c;
	std::string pattern = "aaaa";
	std::string str = "dog cat cat dog";
	EXPECT_FALSE(c.wordPattern(pattern, str));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
