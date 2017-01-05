/*
 * minimumwindowsubstr.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class minimumwindowsubstr {
public:
	string minWindow(string S, string T) {
		if(S.length() < T.length()) return "";

		string res;
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


		return res;
	}
};


int main() {
	minimumwindowsubstr test;
	string s = "ADOBECODEBANC";
	string t = "ABC";
	string ans = test.minWindow(s, t);

	cout << ans << endl;

}
