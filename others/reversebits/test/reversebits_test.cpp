/*
 * reversebits_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "gtest/gtest.h"
#include "reversebits.h"

TEST(testcase_OK, revserse_bits)
{
	solution c;
	int x = 12345676;
	uint32_t res = c.reverseBits(x);
	EXPECT_EQ(x, c.reverseBits(res));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



