/*
 * findkthinsorted.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <vector>
#include <assert.h>
#include <limits.h>

class findkthinsorted {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total = nums1.size() + nums2.size();
		if((total%2) == 1) {  // odd
			return findKth(nums1, 0, nums2, 0, total/2+1);
		} else {                // even
			double t1 = findKth(nums1, 0, nums2, 0, total/2);
			double t2 = findKth(nums1, 0, nums2, 0, total/2+1);
			return (double)(t1+t2)/2;
		}
	}

private:
	double findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
		if(k <= 0 || (size_t)k > nums1.size() + nums2.size()) return 0;
		if(k == 1) return min(nums1[start1], nums2[start2]);
		if((size_t)start1 >= nums1.size()) return nums2[start1+k-1];
		if((size_t)start2 >= nums2.size()) return nums1[start2+k-1];

		int mid1 = start1+k/2-1;
		int mid2 = start2+k/2-1;

		int val1 = ((size_t)mid1 < nums1.size()) ? nums1[mid1] : std::numeric_limits<int>;
		int val2 = ((size_t)mid2 < nums2.size()) ? nums2[mid2] : std::numeric_limits<int>;

		if(val1 < val2) return findKth(nums1, mid1+1, nums2, start2, k-k/2);
		else return findKth(nums1, start1, nums2, mid2+1, k-k/2);
	}

};

int main(int argc, char **argv) {
	findkthinsorted *p = new findkthinsorted();
	vector<int> nums1 {1,2};
	vector<int> nums2 {3,4};
	double ans = p->findMedianSortedArrays(nums1, nums2);
	cout << ans << endl;
}



