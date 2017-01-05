/*
 * longestpalindrome.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "longestpalindrome.h"

string longestpalindrome::longestPalindrome(string s) {
	if (s.length() == 0 || s.length() == 1)
		return s;

	string res;
	int max_len = 0;
	int start = 0;
	int end = 0;
	int n = s.length();

	// issues: 1) no warning when exceed the boundary 2) slow
	// vector<vector<bool>> longest(n, vector<bool>(n,false));

	bool palind[n][n];  // if substr(i, i+j) is palindrome
	for (int i = 0; i < n * n; i++) {
		palind[i / n][i % n] = false;
	}

	palind[0][0] = true;
	for (int j = 1; j <= n; j++) {
		palind[j][j] = true;
		for (int i = 0; i < j; i++) {
			if (s[i] == s[j] && (palind[i + 1][j - 1] == true || j - i < 2)) {
				palind[i][j] = true;
				if (j - i + 1 > max_len) {
					max_len = j - i + 1;
					start = i;
					end = j;
				}
			}
		}
	}

	return s.substr(start, max_len);

}

