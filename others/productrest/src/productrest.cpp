/*
 * productrest.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */


#include "productrest.h"

void productrest::F(int* A, int* B, int N)
{
	if(!A || !B || N < 0) return;

	int zero_cnt = 0;
	int zero_idx = -1;
	int m = 1;

	for(int i = 0; i < N; ++i) {
		B[i] = 0;
		if(A[i]) m = m*A[i];
		else {
			zero_cnt++;
			zero_idx = i;
		}
	}

	if(zero_cnt == 0) {
		for(int i = 0; i < N; ++i) {
			B[i] = m/A[i];
		}
		return;
	}

	if(zero_cnt >= 2) return;

	B[zero_idx] = m;

}
