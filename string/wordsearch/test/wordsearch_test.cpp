/*
 * wordsearch_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "wordsearch.h"
#include "gtest/gtest.h"

TEST(testcase_OK1, wordsearch)
{
	solution c;

	std::vector<std::vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
	std::string word = "ABCCED";

	EXPECT_TRUE(c.exist(board, word));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

