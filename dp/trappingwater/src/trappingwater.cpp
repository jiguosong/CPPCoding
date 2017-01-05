/*
 * trappingwater.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: songjiguo
 */

#include "trappingwater.h"

/*Given n non-negative integers a1, a2, ..., an, where each represents a point
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.*/

int trappingwater::maxArea(vector<int>& height)
{
	int left = 0;
	int right = height.size() - 1;

	int max = 0;
	for(int i = 1; (size_t)i < height.size(); i++) {
		max = std::max(max, (right-left)*std::min(height[left], height[right]));
		if(height[left] < height[right]) ++left;
		else --right;
	}

	return max;
}

/*Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it is able to trap after raining.*/

int trappingwater::trap(int A[], int n)
{
	vector<int> left(n, 0);
	vector<int> right(n, 0);

	int max = A[0];
	left[0] = A[0];
	for(int i = 1; i < n; ++i) {
		if (A[i] < max) {
			left[i] = max;
		} else {
			left[i] = A[i];
			max = A[i];
		}
	}

	max = A[n-1];
	right[n-1] = A[n-1];
	for(int i = n-2; i >= 0; --i) {
		if (A[i] < max) {
			right[i] = max;
		} else {
			right[i] = A[i];
			max = A[i];
		}
	}

	int res = 0;
	for(int i = 0; i < n; ++i) {
		int tmp = std::min(left[i], right[i]);
		if(tmp > A[i]) res += tmp - A[i];
	}

	return res;
}
