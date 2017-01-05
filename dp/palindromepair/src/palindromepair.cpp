/*
 * palindromepair.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

/*
 Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list,
 so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

 Example 1:
 Given words = ["bat", "tab", "cat"]
 Return [[0, 1], [1, 0]]
 The palindromes are ["battab", "tabbat"]

 Example 2:
 Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 */

#include "palindromepair.h"
#include <unordered_map>
#include <algorithm>
using std::unordered_map;

bool isValid(string t) {
	for (int i = 0; (size_t)i < t.size() / 2; ++i) {
		if (t[i] != t[t.size() - 1 - i])
			return false;
	}
	return true;
}

vector<vector<int>> palindromepair::palindromePairs(vector<string>& words)
{
	vector<vector<int>> res;
	unordered_map<string, int> m;
	for (int i = 0; (size_t)i < words.size(); ++i)
		m[words[i]] = i;
	for (int i = 0; (size_t)i < words.size(); ++i) {
		int l = 0, r = 0;
		while (l <= r) {
			string t = words[i].substr(l, r - l);
			reverse(t.begin(), t.end());
			if (m.count(t) && i != m[t]
					&& isValid(
							words[i].substr(l == 0 ? r : 0,
									l == 0 ? words[i].size() - r : l))) {
				if (l == 0)
					res.push_back( { i, (int)m[t] });
				else
					res.push_back( { (int)m[t], i });
			}
			if ((size_t)r < words[i].size())
				++r;
			else
				++l;
		}
	}
	return res;
}
