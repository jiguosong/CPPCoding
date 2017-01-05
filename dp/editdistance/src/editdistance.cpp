/*
 * editdistance.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */


/*Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character*/

#include "editdistance.h"
#include <vector>
#include <array>

int editdistance::minDistance(string word1, string word2)
{
	int m = word1.size();
	int n = word2.size();

	std::vector<std::vector<int> > dist(m+1, std::vector<int>(n+1,0));
	for(int i = 0; i <= m; i++) dist[i][0] = i;
	for(int i = 0; i <= n; i++) dist[0][i] = i;

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(word1[i-1] == word2[j-1]) {
				dist[i][j] = dist[i-1][j-1];
			} else {
				dist[i][j] = std::min(dist[i-1][j-1], std::min(dist[i][j-1], dist[i-1][j])) + 1;
			}
		}
	}

	return dist[m][n];
}




