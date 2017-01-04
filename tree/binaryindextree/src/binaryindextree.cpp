/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
*/

/*Note: this can be extended to 2D as well*/

#include "binaryindextree.h"

void binaryindextree::dummy() 
{
}

binaryindextree::binaryindextree(vector<int> &arrays)
{
	sz_ = arrays.size()+1;    // dummy root. We track the difference
	nums_.resize(sz_);
	bits_.resize(sz_);
	for(int i = 0; i < sz_; ++i) update(i, arrays[i]);
}

void binaryindextree::update(int idx, int val)
{
	++idx;
	int diff = val - nums_[idx];
	for(int j = idx; j < sz_; j += j&(-j)) {
		bits_[j] += diff;    // propogate the difference to the parent
	}
	nums_[idx] = val;
}

int binaryindextree::sumRange(int i, int j)
{
	return getSum(j+1) - getSum(i);
}

int binaryindextree::getSum(int idx)
{
	int res = 0;
	for(int j = idx; j > 0; j -= j&(-j)) {
		res += bits_[j];
	}
	return res;
}
