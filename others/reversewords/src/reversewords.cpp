/*
 * reversewords.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "reversewords.h"
#include <iostream>

static void reverse_helper(std::string &s, int i, int j);

void solution::reverseWords(std::string &s)
{
	if(s.size() == 0) return;

	int j = 0;
	int i = 0;
	bool need_space = false;
	while(1) {
		while((size_t)i < s.size() && s[i] == ' ') ++i;
		if((size_t)i == s.size()) break;
		if(need_space) s[j++] = ' ';
		int tmp = j;
		while((size_t)i < s.size() && s[i] != ' ') {
			s[j] = s[i];
			++j; ++i;
		}
		reverse_helper(s, tmp, j-1);
		need_space = true;
	}
	s.resize(j);
	reverse_helper(s, 0, j-1);
}

static void reverse_helper(std::string &s, int i, int j)
{
	while(i < j) {
		char tmp = s[i];
		s[i++] = s[j];
		s[j--] = tmp;
	}
}
