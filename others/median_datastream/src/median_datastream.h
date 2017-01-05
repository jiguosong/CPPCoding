/*
 * median_datastream.h
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#ifndef MEDIAN_DATASTREAM_H_
#define MEDIAN_DATASTREAM_H_

#include <set>
#include <queue>
using std::priority_queue;

struct bstNode
{
	int val;
	int lessCnt;
	struct bstNode *left, *right;
	bstNode(int v) :
			left(nullptr), right(nullptr), val(v), lessCnt(0)
	{
	}
};

class median_datastream
{
public:
	double findMedian();
	void addNum(int num);

	double findMedian_set();
	void addNum_set(int num);

	double findMedian_BST();
	void addNum_BST(int num);
private:
	priority_queue<long> left_heap, right_heap;
	std::multiset<long> left_set, right_set;

	bstNode *root = nullptr;
	int bst_sz = 0;
};

#endif /* MEDIAN_DATASTREAM_H_ */
