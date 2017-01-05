/*
 * longestcommonsubsequence.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

#include "longestcommonsubsequence.h"

#include <vector>
using std::vector;

int longestcommonsubsequence::getLongestCommonSubsequence(string a, string b)
{
	int res = 0;

	vector<vector<int>> lon(a.size()+1, vector<int>(b.size()+1, 0));

	for(int i = 1; i <= a.size(); ++i) {
		for(int j = 1; j <= b.size(); ++j) {
			if(a[i-1] == b[j-1]) lon[i][j] = lon[i-1][j-1] + 1;
			else lon[i][j] = std::max(lon[i-1][j], lon[i][j-1]);
		}
	}

	return lon[a.size()][b.size()];

}

