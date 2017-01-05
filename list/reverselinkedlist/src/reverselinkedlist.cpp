/*

 */

#include "reverselinkedlist.h"

void reverselinkedlist::dummy()
{
}

ListNode<int> *reverselinkedlist::ReverseList(ListNode<int> *list)
{
	ListNode<int> *prev, *curr, *next;
	prev = nullptr;
	curr = list;
	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}
