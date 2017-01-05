/*
 * reversebits.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include <cstdint>
#include <bitset>
#include "reversebits.h"

uint32_t solution::reverseBits(uint32_t n)
{
	uint32_t res = 0;

	for(int i = 0; i < 32; ++i) {
		int k = n & 1;
		res = (res << 1) + k;
		n = n >> 1;
	}
	return res;
}

