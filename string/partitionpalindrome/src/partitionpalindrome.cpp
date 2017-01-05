/*
 * partitionpalindrome.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

/*

 Given a string s, partition s such that every substring of the partition
 is a palindrome. Return all possible palindrome partitioning of s.

 For example, given s = "aab",
 Return

 [
 ["aa","b"],
 ["a","a","b"]
 ]*/

#include "partitionpalindrome.h"

static bool isvalidPalindrome(string s)
{
	int l = 0;
	int r = s.length() - 1;

	while (l < r) {
		if (s[l] != s[r])
			return false;
		l++;
		r--;
	}

	return true;
}

static void partition_palindrome_helper(string s, int level,
		vector<string> &tmp, vector<vector<string>> &res)
{
	if ((size_t) level == s.length()) {
		res.push_back(tmp);
		return;
	}

	for (int i = level; (size_t) i < s.length(); i++) {
		string tmp_str = s.substr(level, i - level + 1);
		if (isvalidPalindrome(tmp_str)) {
			tmp.push_back(tmp_str);
			partition_palindrome_helper(s, i + 1, tmp, res);
			tmp.pop_back();
		}
	}

	return;

}

vector<vector<string>> partitionpalindrome::partition_palindrome(string s)
{
	int sz = s.length();
	if (sz == 0)
		return {};

	vector<vector<string>> res;
	vector<string> tmp;
	partition_palindrome_helper(s, 0, tmp, res);

	return res;
}

