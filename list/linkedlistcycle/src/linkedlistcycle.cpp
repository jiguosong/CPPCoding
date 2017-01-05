/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

#include <climits>
#include "linkedlistcycle.h"

void linkedlistcycle::dummy() 
{
}

bool linkedlistcycle::hasCycle(ListNode<int> *head)
{
    if(head == nullptr) return false;
    ListNode<int> *fast, *slow;
    fast = slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }

    return false;
}