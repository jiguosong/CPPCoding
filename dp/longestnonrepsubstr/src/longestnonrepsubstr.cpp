/*
 * longestnonrepsubstr.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

/*
 Given a string, find the length of the longest substring without repeating characters.
 For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include "longestnonrepsubstr.h"

#include <unordered_set>
#include <algorithm>
#include <set>

int longestnonrepsubstr::lengthOfLongestNoRepSubstring(string s)
{
	int res = 0;
	int m[256] = { 0 };
	int left = 0;

	for (int i = 0; (size_t) i < s.size(); i++) {
		if (m[s[i]] == 0 || m[s[i]] < left) {
			res = std::max(res, i - left + 1);
		} else {
			left = m[s[i]];
		}
		m[s[i]] = i + 1;  // make it different from 0
	}
	return res;
}

int longestnonrepsubstr::lengthOfLongestNoRepSubstring_set(string s)
{

	std::unordered_set<char> set;
	auto res = 0;
	auto left = 0, right = 0;
	while (right < s.size()) {
		char e = s[right];
		if (set.find(e) == set.end()) {
			set.insert(e);
			res = std::max(res, (int) set.size());
			++right;
		} else {
			set.erase(s[left]);
			++left;
		}
	}
	return res;

}

