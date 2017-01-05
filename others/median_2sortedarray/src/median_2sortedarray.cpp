/*
 * median_2sortedarray.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#include "median_2sortedarray.h"
#include <iostream>
#include <climits>

/*There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity
should be O(log (m+n)).*/
double median_2sortedarray::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int total = nums1.size() + nums2.size();
	if(total&1) {  // odd
		return findKth(nums1, 0, nums2, 0, total/2+1);
	} else {                // even
		double t1 = findKth(nums1, 0, nums2, 0, total/2);
		double t2 = findKth(nums1, 0, nums2, 0, total/2+1);
		return (t1+t2)/2;
	}
}

double median_2sortedarray::findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
	if (nums1.size() == (size_t)i) return nums2[j + k - 1];
	if (nums2.size() == (size_t)j) return nums1[i + k - 1];

	if (k == 1) return std::min(nums1[i], nums2[j]);
	int mid1 = std::min(i + k / 2, int(nums1.size()));
	int mid2 = std::min(j + k / 2, int(nums2.size()));
	if (nums1[mid1 - 1] < nums2[mid2 - 1])
		return findKth(nums1, mid1, nums2, j, k - mid1 + i);
	else
		return findKth(nums1, i, nums2, mid2, k - mid2 + j);
}


//double median_2sortedarray::findKth(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k)
//{
//	if((size_t)s1 >= nums1.size()) return nums2[s2+k-1];
//	if((size_t)s2 >= nums2.size()) return nums1[s1+k-1];
//
//	if(k == 1) return std::min(nums1[s1], nums2[s2]);
//
//	int m1 = s1+k/2-1;
//	int m2 = s2+k/2-1;
//
//	int mid1 = ((size_t)m1 < nums1.size()) ? nums1[m1] : INT_MAX;
//	int mid2 = ((size_t)m2 < nums2.size()) ? nums2[m2] : INT_MAX;
//
//	if(mid1 < mid2) return findKth(nums1, mid1+1, nums2, s2, k-k/2);
//	else return findKth(nums1, s1, nums2, mid2+1, k-k/2);
//
//}


/*public int findKth(int k, int[] nums1, int[] nums2, int s1, int s2){
    if(s1>=nums1.length)
        return nums2[s2+k-1];

    if(s2>=nums2.length)
        return nums1[s1+k-1];

    if(k==1)
        return Math.min(nums1[s1], nums2[s2]);

    int m1 = s1+k/2-1;
    int m2 = s2+k/2-1;

    int mid1 = m1<nums1.length?nums1[m1]:Integer.MAX_VALUE;
    int mid2 = m2<nums2.length?nums2[m2]:Integer.MAX_VALUE;

    if(mid1<mid2){
        return findKth(k-k/2, nums1, nums2, m1+1, s2);
    }else{
        return findKth(k-k/2, nums1, nums2, s1, m2+1);
    }
}*/

/*
double median_2sortedarray::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1) {
            return findKth(nums1, 0, nums2, 0, total / 2 + 1);
        } else {
            return (findKth(nums1, 0, nums2, 0, total / 2) + findKth(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
        }
    }
double median_2sortedarray::findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
	if (nums1.size() - i > nums2.size() - j) return findKth(nums2, j, nums1, i, k);
	if (nums1.size() == i) return nums2[j + k - 1];
	if (k == 1) return std::min(nums1[i], nums2[j]);
	int pa = std::min(i + k / 2, int(nums1.size())), pb = j + k - pa + i;
	if (nums1[pa - 1] < nums2[pb - 1])
		return findKth(nums1, pa, nums2, j, k - pa + i);
	else if (nums1[pa - 1] > nums2[pb - 1])
		return findKth(nums1, i, nums2, pb, k - pb + j);
	else
		return nums1[pa - 1];
}
*/
