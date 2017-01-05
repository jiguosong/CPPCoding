/*
 * median_2sortedarray.h
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#ifndef MEDIAN_2SORTEDARRAY_H_
#define MEDIAN_2SORTEDARRAY_H_

#include <vector>

using std::vector;

class median_2sortedarray {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	double findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k);
};



#endif /* MEDIAN_2SORTEDARRAY_H_ */
