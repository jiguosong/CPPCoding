/*
 * wordladder.h
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#ifndef WORDLADDER_H_
#define WORDLADDER_H_

#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict);
};



#endif /* WORDLADDER_H_ */
