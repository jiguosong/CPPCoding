/*

*/

#include "searchentryequalindex.h"

void searchentryequalindex::dummy() {
}

int searchentryequalindex::FindIndexEqualEntry(vector<int> nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right-left)/2;
        if(nums[mid] == mid) return mid;
        else if(nums[mid] < mid) right = mid -1;
        else left = mid + 1;
    }

    return -1;
}


