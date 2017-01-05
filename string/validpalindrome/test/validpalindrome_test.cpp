/* googletest unit test for C++ */

#include "validpalindrome.h"

#include "gtest/gtest.h"
#include <iostream>

using std::cout; 
using std::endl;

TEST(testcase_OK1, validpalindrome)
{
	validpalindrome c;
	string s = "abc";
	ASSERT_FALSE(c.isValidPalindromeStr(s));
}

TEST(testcase_OK2, validpalindrome)
{
	validpalindrome c;
	string s = "abba";
	ASSERT_TRUE(c.isValidPalindromeStr(s));
}

TEST(testcase_OK3, validpalindrome)
{
	validpalindrome c;
	string s = "1bb1";
	ASSERT_TRUE(c.isValidPalindromeStr(s));
}


TEST(testcase_OK4, validpalindrome)
{
	validpalindrome c;
	string s = "";
	ASSERT_TRUE(c.isValidPalindromeStr(s));
}

TEST(testcase_OK5, validpalindrome)
{
	validpalindrome c;
	string s = "a";
	ASSERT_TRUE(c.isValidPalindromeStr(s));
}

TEST(testcase_OK6, validpalindrome)
{
	validpalindrome c;
	string s = "A man, a plan, a canal: Panama";
	ASSERT_TRUE(c.isValidPalindromeStr(s));
}

TEST(testcase_OK7, validpalindrome)
{
	validpalindrome c;
	string s = "ac ba";
	ASSERT_FALSE(c.isValidPalindromeStr(s));
}

TEST(testcase_OK8, validpalindrome)
{
	validpalindrome c;
	int num = 123;
	ASSERT_FALSE(c.isPalindromenumber(num));
}

TEST(testcase_OK9, validpalindrome)
{
	validpalindrome c;
	int num = 121;
	ASSERT_TRUE(c.isPalindromenumber(num));
}

TEST(testcase_OK10, validpalindrome)
{
	validpalindrome c;
	int num = 100000001;
	ASSERT_TRUE(c.isPalindromenumber(num));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
