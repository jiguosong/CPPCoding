/*
 * median_2sortedarray_test.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#include "median_2sortedarray.h"

#include "gtest/gtest.h"

TEST(testcase_OK1, median_2sortedarray) {
	median_2sortedarray c;

	vector<int> nums1 { 1, 2 };
	vector<int> nums2 { 3, 4 };
	double ans = c.findMedianSortedArrays(nums1, nums2);
	ASSERT_EQ(ans, 2.5);
}

TEST(testcase_OK2, median_2sortedarray) {
	median_2sortedarray c;

	vector<int> nums1 { 1, 12, 15, 26, 51};
	vector<int> nums2 { 2, 9, 17, 30, 45 };
	double ans = c.findMedianSortedArrays(nums1, nums2);
	ASSERT_EQ(ans, 16);
}

GTEST_API_ int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

