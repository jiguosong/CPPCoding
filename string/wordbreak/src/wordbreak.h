/*
 * wordbreak.h
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#ifndef WORDBREAK_H_
#define WORDBREAK_H_

#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict);
};



#endif /* WORDBREAK_H_ */
