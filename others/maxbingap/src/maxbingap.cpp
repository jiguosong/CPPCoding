/*
 * maxbingap.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: songjiguo
 */

#include "maxbingap.h"
#include <algorithm>

int maxbingap::max_bin_gap_N(int num)
{
	int res = 0;
	int count = -1;

	while(num > 0) {
		if(num & 1) {
			res = std::max(res, count);
			count = 0;
		} else {
			if(count >= 0) ++count;
		}
		num = num >> 1;
	}

	return res;
}


int maxbingap::max_bin_gap_LogN(int num)
{

}
