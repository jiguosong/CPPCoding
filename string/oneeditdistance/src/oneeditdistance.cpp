/*

 Given two strings S and T, determine if they are both one edit distance apart.

 */

#include "oneeditdistance.h"
#include <cmath>

void oneeditdistance::dummy()
{
}

static bool diffbyonemore(string &s1, string &s2)   // s2 is longer
{
	int i = 0;
	int j = 0;
	int sz = s1.size();
	while (i < sz && s1[i] == s2[j]) {
		++i;
		++j;
	}
	if (j == sz + 1)
		return true;
	else {
		++j;
		return s1.substr(i).compare(s2.substr(j)) == 0;
	}
}

static bool diffbyone(string &s1, string &s2) // same length, but one char different
{
	int i = 0;
	int j = 0;
	int sz = s1.size();
	int cnt = 0;
	while (i < sz) {
		if (s1[i++] != s2[j++])
			++cnt;
	}
	return cnt == 1;
}

bool oneeditdistance::isOneEditDistance(string s, string t)
{
	int diff = s.size() - t.size();
	if (std::abs(diff) > 1) {
		return false;
	} else if (diff == 1) {  // s is one char longer than t
		return diffbyonemore(t, s);
	} else if (diff == -1) {  // t is one char longer than t
		return diffbyonemore(s, t);
	} else {
		return diffbyone(s, t);
	}
}

