/*
 * reversenumber.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include <cstdlib>
#include <climits>

#include "reversenumber.h"

using namespace std;

int solution::reverse(int x)
{
	int res = 0;

	while(x) {
		if(abs(x) > INT_MAX/10) return 0;
		res = res*10 + x%10;
		x = x/10;
	}

	return res;
}
