/*
 * editdistance_test.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#include "editdistance.h"

#include "gtest/gtest.h"

TEST(testcase_OK1, editdistance)
{
	editdistance c;

	string word1 = "asdsd";
	string word2 = "zxy";

	ASSERT_EQ(5, c.minDistance(word1, word2));
}

TEST(testcase_OK2, editdistance)
{
	editdistance c;

	string word1 = "a";
	string word2 = "a";

	ASSERT_EQ(0, c.minDistance(word1, word2));
}

TEST(testcase_OK3, editdistance)
{
	editdistance c;

	string word1 = "";
	string word2 = "abcdefghijklm";

	ASSERT_EQ(word2.size(), c.minDistance(word1, word2));
}

TEST(testcase_OK4, editdistance)
{
	editdistance c;

	string word1 = "";
	string word2 = "";

	ASSERT_EQ(word2.size(), c.minDistance(word1, word2));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



