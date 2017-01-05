/*
 * longestnonrepsubstr_test.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

#include "longestnonrepsubstr.h"
#include "gtest/gtest.h"
#include <iostream>
#include <random>

using std::cout;
using std::endl;

static int getRandom(int lower, int upper)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(lower, upper);
	return dist(gen);
}

// first way to generate random string of len
string getRandomString(int len)
{
	string str(len, ' ');
	for (int i = 0; i < len; ++i) {
		int randchar =
				getRandom(0, std::numeric_limits<int>::max()) % (26 + 26 + 10);
		if (randchar < 26) {
			str[i] = 'a' + randchar;
		} else if (randchar < 26 + 26) {
			str[i] = 'A' + randchar - 26;
		} else {
			str[i] = '0' + randchar - 26 - 26;
		}
	}

	return str;
}


TEST(testcase_OK1, longestnonrepsubstr)
{
	longestnonrepsubstr c;

	string s = "abcabcbb";
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring(s), 3);
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring_set(s), 3);
}

TEST(testcase_OK2, longestnonrepsubstr)
{
	longestnonrepsubstr c;

	string s = "bbbbb";
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring(s), 1);
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring_set(s), 1);
}


TEST(testcase_OK3, longestnonrepsubstr)
{
	longestnonrepsubstr c;

	string s = "";
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring(s), 0);
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring_set(s), 0);
}

TEST(testcase_OK4, longestnonrepsubstr)
{
	longestnonrepsubstr c;

	string s = "abcdefg";
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring(s), 7);
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring_set(s), 7);
}

TEST(testcase_OK5, longestnonrepsubstrrandom)
{
	longestnonrepsubstr c;

	string s = getRandomString(10);
	cout << s << endl;
	cout << c.lengthOfLongestNoRepSubstring(s) << endl;
	cout << c.lengthOfLongestNoRepSubstring_set(s) << endl;
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



