/*
 * add2number.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include "add2number.h"

ListNode<int> * solution::addTwoNumbers(ListNode<int> *l1, ListNode<int> *l2) {
	 if (!l1 && !l2) return nullptr;
	 if (l1 && !l2) return l1;
	 if (l2 && !l1) return l2;

	 int sum, digit, carry;
	 carry = 0;
	 ListNode<int> *head = nullptr;
	 ListNode<int> *curr = head;

	 ListNode<int> *p1, *p2;
	 p1 = l1;
	 p2 = l2;

	 while (p1 && p2) {
		 sum = p1->data + p2->data;
		 digit = sum%10 + carry;
		 carry = sum/10;
		 //ListNode<int> *tmp = new ListNode(digit);
		 ListNode<int> *tmp = GetNode(digit);
		 if (!head) {
			 head = tmp;
			 curr = tmp;
		 }  else {
			 curr->next = tmp;
			 curr = curr->next;
		 }
		 p1 = p1->next;
		 p2 = p2->next;
	 }

	 if (p1) curr->next = p1;
	 if (p2) curr->next = p2;

	 return head;
}
