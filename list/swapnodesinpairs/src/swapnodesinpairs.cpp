/*
    Given a linked list, swap every two adjacent nodes and return its head.

    For example,
    Given 1->2->3->4, you should return the list as 2->1->4->3.

    Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/


#include "swapnodesinpairs.h"

void swapnodesinpairs::dummy() 
{
}

ListNode<int> *swapnodesinpairs::SwapNodePairs(ListNode<int> *head)
{
	if(head == nullptr) return head;


	ListNode<int> *prev, *next, *c1, *c2, *dummy;
	dummy = new ListNode<int>(-1);
	dummy->next = head;
	prev = dummy;
	c1 = head;
	c2 = head->next;
	while(c1 && c2) {
		next = c2->next;
		c2->next = c1;
		c1->next = next;
		prev->next = c2;
		prev = c1;
		if(!c1->next) break;
		c1 = c1->next;
		c2 = c1->next;
	}

	ListNode<int> *res = dummy->next;
	delete dummy;
	return res;
}
