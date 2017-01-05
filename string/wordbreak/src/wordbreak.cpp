/*
 * wordbreak.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "wordbreak.h"
#include <vector>

using std::vector;

bool solution::wordBreak(string s, unordered_set<string> &dict)
{
	if(dict.empty()) return false;
	if(s.empty()) return false;

	vector<bool> find(s.size()+1, false);
	find[0] = true;

	for(unsigned int i = 0; i < s.size()+1; ++i) {
		for(unsigned int j = 0; j < i; ++j) {
			if(find[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
				find[i] = true;  // find one break
				break;
			}
		}
	}

	return find[s.size()];

}

