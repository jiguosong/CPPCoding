/* googletest unit test for C++ */

#include "productrest.h"
#include "gtest/gtest.h"
#include <iostream>

using std::cout; 
using std::endl;

TEST(testcase_OK1, productrest)
{
	productrest c;
	int A[4] = {2,1,5,9};
	int B[4] = {0};
	c.F(A, B, 4);

	ASSERT_EQ(B[0], 45);
	ASSERT_EQ(B[1], 90);
	ASSERT_EQ(B[2], 18);
	ASSERT_EQ(B[3], 10);
}

TEST(testcase_OK2, productrest)
{
	productrest c;
	int A[6] = {2,1,5,9, 0, 2};
	int B[6] = {0};
	c.F(A, B, 6);

	ASSERT_EQ(B[0], 0);
	ASSERT_EQ(B[1], 0);
	ASSERT_EQ(B[2], 0);
	ASSERT_EQ(B[3], 0);
	ASSERT_EQ(B[4], 180);
	ASSERT_EQ(B[5], 0);
}

TEST(testcase_OK3, productrest)
{
	productrest c;
	int A[6] = {2,0,5,9, 0, 2};
	int B[6] = {0};
	c.F(A, B, 6);

	ASSERT_EQ(B[0], 0);
	ASSERT_EQ(B[1], 0);
	ASSERT_EQ(B[2], 0);
	ASSERT_EQ(B[3], 0);
	ASSERT_EQ(B[4], 0);
	ASSERT_EQ(B[5], 0);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
