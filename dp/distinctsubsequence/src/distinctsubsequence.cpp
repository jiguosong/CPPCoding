/*
 * distinctsubsequence.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

#include "distinctsubsequence.h"

/*Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by
deleting some (can be none) of the characters without disturbing the relative
positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE"
while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.*/


//int distinctsubsequence::numDistinct(string S, string T)
int numDistinct(string S, string T)
{
	int m = S.size();
	int n = T.size();

	int ways_to_change[m+1][n+1];

	// init
	for(int i = 0; i <= m; i++) {
		ways_to_change[i][0] = 1;  // delete all to get ""
		for(int j = 1; j <= n; j++) {
			ways_to_change[i][j] = 0;
		}
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(S[i-1] == T[j-1]) ways_to_change[i][j] = ways_to_change[i-1][j-1] + ways_to_change[i-1][j];
			else ways_to_change[i][j] = ways_to_change[i-1][j];
		}
	}

	return ways_to_change[m][n];

}

