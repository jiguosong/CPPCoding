/*
 * add2number.h
 *
 *  Created on: Nov 15, 2016
 *      Author: songjiguo
 */

#ifndef ADD2NUMBER_H_
#define ADD2NUMBER_H_

#include "List.h"

/*
struct ListNode {
      int data;
      ListNode *next;
      ListNode(int x) : data(x), next(nullptr) {}
};
*/

class solution {
public:
	ListNode<int> *addTwoNumbers(ListNode<int> *l1, ListNode<int> *l2);
};


#endif /* ADD2NUMBER_H_ */
