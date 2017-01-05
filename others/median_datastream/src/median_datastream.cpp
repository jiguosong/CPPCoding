/*
 * median_datastream.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#include "median_datastream.h"

/*
 Median is the middle value in an ordered integer list. If the size of the list is
 even, there is no middle value. So the median is the mean of the two middle value.
 Examples:

 [2,3,4] , the median is 3

 [2,3], the median is (2 + 3) / 2 = 2.5

 Design a data structure that supports the following two operations:

 void addNum(int num) - Add a integer number from the data stream to the data structure.
 double findMedian() - Return the median of all elements so far.

 For example:

 add(1)
 add(2)
 findMedian() -> 1.5
 add(3)
 findMedian() -> 2
 */

/*
 https://discuss.leetcode.com/topic/27521/short-simple-java-c-python-o-log-n-o-1/2

 I keep two heaps (or priority queues):

 Max-heap small has the smaller half of the numbers.
 Min-heap large has the larger half of the numbers.

 This gives me direct access to the one or two middle values (they're the tops
 of the heaps), so getting the median takes O(1) time. And adding a number
 takes O(log n) time.

 Supporting both min- and max-heap is more or less cumbersome, depending on
 the language, so I simply negate the numbers in the heap in which I want the
 reverse of the default order. To prevent this from causing a bug with -2^31
 (which negated is itself, when using 32-bit ints), I use integer types larger
 than 32 bits.

 Using larger integer types also prevents an overflow error when taking the
 mean of the two middle numbers. I think almost all solutions posted previously
 have that bug.

 */

double median_datastream::findMedian()
{
	double res = 0;

	if (left_heap.size() > right_heap.size())
		res = left_heap.top();
	else
		res = double(left_heap.top() - right_heap.top()) / 2;
	return res;
}

void median_datastream::addNum(int num)
{
	left_heap.push(num);
	/*	Since by default, the heap is max_heap,
	 * so we save the negative in the right_heap*/
	right_heap.push(-left_heap.top());
	left_heap.pop();

	if (right_heap.size() > left_heap.size()) {
		left_heap.push(-right_heap.top());
		right_heap.pop();
	}
}

double median_datastream::findMedian_set()
{
	double res = 0;

	if (left_set.size() > right_set.size())
		return *left_set.begin();
	else
		return double((*left_set.begin() - *right_set.begin())) / 2; // we saved negative in right earlier

}

void median_datastream::addNum_set(int num)
{
	left_set.insert(num);
	right_set.insert(-*left_set.begin());
	left_set.erase(left_set.begin());

	if (right_set.size() > left_set.size()) {
		left_set.insert(-*right_set.begin());
		right_set.erase(right_set.begin());
	}
}


// A single BST is a bad idea to do this -- updating requires n^2

#include <iostream>

double median_datastream::findMedian_BST()
{
	if (root == nullptr)
		return 0;

	int mid = (bst_sz % 1) ? bst_sz / 2 : bst_sz / 2 - 1;
	std::cout << "BST size " << bst_sz << std::endl;
	std::cout << "mid lesscnt " << mid << std::endl;
	bstNode *p = root;
	while (p) {
		if (p->lessCnt == mid) {
			std::cout << "AAA p->lessCnt " << p->lessCnt << std::endl;
			break;
		} else if (p->lessCnt < mid) {
			std::cout << "BBB p->lessCnt " << p->lessCnt << std::endl;
			p = p->right;
		} else {
			std::cout << "CCC p->lessCnt " << p->lessCnt << std::endl;
			p = p->left;
		}
	}

	if (p == nullptr)
		return 0;  // unlikely
	if (bst_sz & 1)
		return p->val;
	else
		return (p->val + p->right->val) / 2;

}

static void helper(bstNode *root, bstNode *newnode)
{
	bstNode *p = root;
	if (p == nullptr) p = newnode;
	else if (newnode->val < root->val) {  // left
		++p->lessCnt;
		helper(p->left, newnode);
	} else {
		newnode->lessCnt += p->lessCnt;    // right
		helper(p->right, newnode);
	}
}

void median_datastream::addNum_BST(int num)
{
	bstNode *newnode = new bstNode(num);
	++bst_sz;
	if (root == nullptr) {
		root = newnode;
		return;
	}

	helper(root, newnode);

}



/*// Find number of nodes in BST in O(log n)
 * https://www.ocf.berkeley.edu/~wwu/cgi-bin/yabb/YaBB.cgi?board=riddles_cs;action=display;num=1196318898
 *

void findNumNodesInBST()
{
    node *p=root;
    int numNodes=0;
    while(p)
    {
         numNodes+=p->leftCount+1;
         p=p->right;
    }
    findMedian(0,numNodes,root);
}

void findMedian(int addFactor,int n,node *p)
{
    while(true)
    {
        // if p->data==median
        if( addFactor + p->leftCount == floor((n-1)/2) )
        {
             printf("%d",p->data);
             break;
        } // end if
        // if p->data < median
        if( addFactor + p->leftCount < floor((n-1)/2) )
        {
            addFactor+=p->leftCount+1;
            p=p->right;
        } // end if
        else              // if p->data>median
            p=p->left;
    } // end while
} */
