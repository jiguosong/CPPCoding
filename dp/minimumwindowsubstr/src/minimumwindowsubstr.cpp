/*
 * minimumwindowsubstr.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".
*/

#include "minimumwindowsubstr.h"

#include <unordered_map>
using std::unordered_map;

string minimumwindowsubstr::minWindow(string S, string T)
{
	string res = "";
	if (T.size() > S.size()) return res;
	unordered_map<char, int> m;

	for (size_t i = 0; i < T.size(); ++i) {
		if (m.find(T[i]) != m.end())
			++m[T[i]];
		else
			m[T[i]] = 1;
	}

	int left = 0, count = 0, minLen = S.size() + 1;
	for (size_t right = 0; right < S.size(); ++right) {
		if (m.find(S[right]) != m.end()) {
			--m[S[right]];
			if (m[S[right]] >= 0)
				++count;
			while ((size_t)count == T.size()) {
				if (right - left + 1 < (size_t)minLen) {
					minLen = right - left + 1;
					res = S.substr(left, minLen);
				}
				if (m.find(S[left]) != m.end()) {
					++m[S[left]];
					if (m[S[left]] > 0)
						--count;
				}
				++left;
			}
		}
	}

	return res;

/*	string res = "";
	if(S.length() < T.length()) return res;

	unordered_map<char, int> sourceMap;
	unordered_map<char, int> targetMap;

	for(int i = 0; (size_t)i < T.length(); ++i) {
		if(targetMap.find(T[i]) != targetMap.end()) ++targetMap[T[i]];
		else targetMap[T[i]] = 1;
	}

	int count = 0;
	int left = 0;
	int min_sz = 0;
	for(int i = 0; (size_t)i < S.length(); ++i) {
		char c = S[i];

		if(targetMap.find(c) != targetMap.end()) {
			if(sourceMap.find(c) != sourceMap.end()) {
				if(sourceMap[c] < targetMap[c]) count++;
				++sourceMap[c];
			} else {
				sourceMap[c] = 1;
				count++;
			}
		}

		if((size_t)count == targetMap.size()) {
			char c = S[left];
			while(sourceMap.find(c) == sourceMap.end() || sourceMap[c] > targetMap[c]) {
				if(sourceMap.find(c) != sourceMap.end() && sourceMap[c] > targetMap[c]) {
					--sourceMap[c];
				}
				left++;
				c = S[left];
			}

			min_sz = i-left+1;
			res = S.substr(left, min_sz);
		}
	}

	return res;*/
}
