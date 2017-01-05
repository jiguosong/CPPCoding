/*
 * alignedAllocate_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "gtest/gtest.h"
#include "../src/alignedAllocate.h"

#include <iostream>

using std::cout;
using std::endl;

TEST(testcase_OK1, alignedAllocate)
{
	alignedAllocate_test c;

	size_t sizeInBytes = 1999;
	size_t alignment = 32;

	int *p = (int *)c.alignedAllocate(sizeInBytes, alignment);
	ASSERT_EQ((int)p%alignment, 0);
	c.alignned_free(p);
	p = nullptr;
}

TEST(testcase_Fail1, alignedAllocate)
{
	alignedAllocate_test c;

	size_t sizeInBytes = 1999;
	size_t alignment = 31;

	int *p = (int *)c.alignedAllocate(sizeInBytes, alignment);
	ASSERT_NE((int)p%alignment, 0);
	c.alignned_free(p);
	p = nullptr;
}


TEST(testcase_Fail2, alignedAllocate)
{
	alignedAllocate_test c;

	size_t sizeInBytes = 0;
	size_t alignment = 31;

	// allocate for alignment anyway
	int *p = (int *)c.alignedAllocate(sizeInBytes, alignment);
	ASSERT_NE((int)p%alignment, 0);
	c.alignned_free(p);
	p = nullptr;
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


