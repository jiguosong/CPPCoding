#include "containduplicate.h"
#include <unordered_map>
#include <map>

void containduplicate::dummy()
{
}

/*
 Given an array of integers, find if the array contains any duplicates.
 Your function should return true if any value appears at least twice in
 the array, and it should return false if every element is distinct.
 */
bool containduplicate::containDuplicates(vector<int> &nums)
{
	std::unordered_map<int, int> map;

	for (auto e : nums) {
		if (map.count(e))
			return true;
		++map[e];
	}
	return false;
}

/*
 Given an array of integers and an integer k, find out whether there are
 two distinct indices i and j in the array such that nums[i] = nums[j] and
 the difference between i and j is at most k
 */
bool containduplicate::containDuplicatesatMostK(vector<int> &nums, int k)
{
	std::unordered_map<int, int> map;

	for (int i = 0; i < nums.size(); ++i) {
		if (map.count(nums[i]) && (std::abs(i - map[nums[i]]) <= k))
			return true;
		map[nums[i]] = i;
	}

	return false;
}

/*
 Given an array of integers, find out whether there are two distinct
 indices i and j in the array such that the difference between nums[i]
 and nums[j] is at most t and the difference between i and j is at most k.
 */
bool containduplicate::containDuplicatesatMostKMostT(vector<int> &nums, int k,
		int t)
{

	std::map<int, int> map;
	int left = 0;
	int right = 0;

	for (; right < nums.size(); ++right) {
		if (right - left > k && map[nums[left]] == left)
			map.erase(nums[left++]);
		auto it = map.lower_bound(nums[right] - t);
		if(it != map.end() && std::abs(it->first - nums[right]) <= t) return true;
		map[nums[right]] = right;
	}

	return false;
}

