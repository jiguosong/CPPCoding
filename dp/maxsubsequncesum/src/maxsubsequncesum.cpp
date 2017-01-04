/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/

#include <climits>
#include "maxsubsequncesum.h"

void maxsubsequncesum::dummy() {
}

int maxsubsequncesum::maxsubsequencesum(vector<int> &nums) {
    int n = nums.size();
    int max = INT_MIN;
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        tmp = std::max(tmp + nums[i], nums[i]);
        max = std::max(max, tmp);
    }
    return max;
}


