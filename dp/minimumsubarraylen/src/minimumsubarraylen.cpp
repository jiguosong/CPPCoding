/*




 */

#include "minimumsubarraylen.h"
#include <climits>

void minimumsubarraylen::dummy()
{
}

int minimumsubarraylen::minSubArrayLen(int s, vector<int>& nums)
{

	if (nums.empty())
		return 0;
	int sz = nums.size();

	int left = 0;
	int right = 0;

	int min = INT_MAX;
	int sum = 0;
	while (right < sz) {
		sum += nums[right];
		while (sum >= s && left <= right) {
			min = std::min(min, right - left + 1);
			sum -= nums[left++];
		}
		++right;
	}

	if(min == INT_MAX) return 0;
	else return min;
}
