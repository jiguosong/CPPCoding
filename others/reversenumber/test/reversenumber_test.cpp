/*
 * reversenumber_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "gtest/gtest.h"
#include "reversenumber.h"

TEST(testcase1, reverse_number) {
	solution c;
	int x = 123;
	int res = c.reverse(x);
	EXPECT_EQ(res, 321);
}

TEST(testcase_zero, reverse_number) {
	solution c;
	int x = 0;
	int res = c.reverse(x);
	EXPECT_EQ(res, 0);
}


TEST(testcase_overflow, reverse_number) {
	solution c;
	int x = 1000000009;
	int res = c.reverse(x);
	EXPECT_EQ(res, 0);
}


GTEST_API_ int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

