/* Given two arrays of length m and n with digits 0-9 representing two numbers.
 * Create the maximum number of length k <= m + n from digits of the two.
 * The relative order of the digits from the same array must be preserved.
 * Return an array of the k digits.

 Example 1:

 nums1 = [3, 4, 6, 5]
 nums2 = [9, 1, 2, 5, 8, 3]
 k = 5
 return [9, 8, 6, 5, 3]

 Example 2:

 nums1 = [6, 7]
 nums2 = [6, 0, 4]
 k = 5
 return [6, 7, 6, 0, 4]

 Example 3:

 nums1 = [3, 9]
 nums2 = [8, 9]
 k = 3
 return [9, 8, 9]*/

#include "createmaxnumber.h"
#include "algorithm"

static vector<int> findmaxnum(vector<int> &nums, int k)
{
	if (k <= 0)
		return {};

	int drop  = nums.size() - k;

	vector<int> res;
	for (int e : nums) {
		while (drop && !res.empty() && res.back() < e) {
			res.pop_back();
			--drop;
		}
		res.push_back(e);
	}

	res.resize(k);
	return res;

}

static vector<int> mergetest(vector<int> &nums1, vector<int> &nums2)
{
	vector<int> out;
	auto a1 = nums1.begin();
	auto e1 = nums1.end();
	auto a2 = nums2.begin();
	auto e2 = nums2.end();

	while (a1 != e1 || a2 != e2) {
		int t = std::lexicographical_compare(a1, e1, a2, e2) ? *a2++ : *a1++;
		out.push_back(t);
	}

	return out;
}

vector<int> createmaxnumber::maxNumber(vector<int>& nums1, vector<int>& nums2,
		int k)
{
	if (k <= 0)
		return {};

	int n1 = nums1.size();
	int n2 = nums2.size();

	vector<int> res;
	for (int i = std::max(k - n2, 0); i <= std::min(k, n1); ++i) {
		vector<int> t1 = findmaxnum(nums1, 2);
		vector<int> t2 = findmaxnum(nums2, 2);
		res = std::max(res, mergetest(t1, t2));
	}

	return res;
}

