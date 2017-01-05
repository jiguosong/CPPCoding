/*
 * dividearray.h
 *
 *  Created on: Nov 30, 2016
 *      Author: songjiguo
 */

#ifndef DIVIDEARRAY_H_
#define DIVIDEARRAY_H_

#include <vector>
using std::vector;

class dividearray {
public:
	bool isArrayDividableInEqualSums(vector<int> &nums);
	bool isArrayDividableInEqualSums_Set(vector<int> &nums);
	vector<vector<int>> allArrayDividableInEqualSums_Set(vector<int> &nums);
};

#endif /* DIVIDEARRAY_H_ */
