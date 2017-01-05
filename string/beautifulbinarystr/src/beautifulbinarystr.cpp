/*

 https://www.hackerrank.com/challenges/beautiful-binary-string

 */

#include "beautifulbinarystr.h"

void beautifulbinarystr::dummy()
{
}

int beautifulbinarystr::minStepstoBeautifulStr(string &str)
{
	int res = 0;

	char prev_prev = str[0];
	char prev = str[1];
	char curr, tmp;
	for(int i = 2; i < str.size(); ++ i) {
		curr = str[i];
		if(prev_prev == '0' && prev == '1' && curr == '0') {
			curr = '1';
			++res;
		}
		prev_prev = prev;
		prev = curr;
	}

	return res;
}
