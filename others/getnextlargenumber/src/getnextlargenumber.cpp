/*
 * getnextlargenumber.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: songjiguo
 */

/*Given a number whose digits are unique, find the next larger number that can be formed with those digits.*/

#include "getnextlargenumber.h"
#include <vector>
using std::vector;

#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
void PrintVector(const vector<T> &vec)
{
	for(size_t i = 0; i < vec.size(); ++i) cout << vec[i] << ' ';
	cout << endl;
}

int getnextlargenumber::getNextLarger(int decimalNumber)
{
	int sign = 1;
	if(decimalNumber < 0) sign = -1;
	decimalNumber = sign*decimalNumber;

	vector<int> digits;
	while(decimalNumber) {
		int tmp = decimalNumber%10;
		decimalNumber /= 10;
		digits.push_back(tmp);
	}
	std::reverse(digits.begin(), digits.end());

	int idx;
	for(idx = digits.size() - 1; idx > 0 ; --idx) {
		if(sign == 1 && digits[idx] > digits[idx-1]) break;    // for positive
		if(sign == -1 && digits[idx] < digits[idx-1]) break;   // for negative
	}

	if(idx >= 1) {
		int tmp = digits[idx];
		digits[idx] = digits[idx-1];
		digits[idx-1] = tmp;
	}

	std::sort(digits.begin()+idx, digits.end());

	int res = 0;
	for(int i : digits) res = res*10 + i;

	return res*sign;
}
