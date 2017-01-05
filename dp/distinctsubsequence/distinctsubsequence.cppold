/*
 * distinctsubsequence.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <string>

class distinctsubsequence {
public:
	int numDistinct(string S, string T) {
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
};

int main(int aragc, char **argv) {
	distinctsubsequence *p = new distinctsubsequence();
	string S = "rabbbit";
	string T = "rabbit";
	int ans = p->numDistinct(S, T);
	cout << ans << endl;
	delete p;
}

