/*
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

 You may not alter the values in the nodes, only nodes itself may be changed.

 Only constant memory is allowed.

 For example,
 Given this linked list: 1->2->3->4->5

 For k = 2, you should return: 2->1->4->3->5

 For k = 3, you should return: 3->2->1->4->5

 */

#include "swapnodesKgroup.h"

void swapnodesKgroup::dummy()
{
}

static ListNode<int> *swap_helper(ListNode<int> *head, ListNode<int> *last)
{
	ListNode<int> *pre = head ,* p = head->next;
	while (p != last) {
		pre->next = p->next;
		p->next = head;
		head = p;
		p = pre->next;
	}
	return head;
}

ListNode<int> *swapnodesKgroup::SwapNodeKGroup(ListNode<int> *head, int k)
{
	if (!head || k == 1)
		return head;
	ListNode<int> *p = head;
	ListNode<int> *pre = new ListNode<int>(-1);
	ListNode<int> *res = pre;
	pre->next = head;
	while (head) {
		int i = 0;
		for (p = head; i < k && p; ++i)
			p = p->next;

		if (i < k)
			break;
		pre->next = swap_helper(head, p);
		pre = head;
		head = head->next;
	}

	return res->next;

}
