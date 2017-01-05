/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include "removeduplicats.h"

void removeduplicats::dummy() {
}

ListNode<int> *removeduplicats::removeDuplicate(ListNode<int> *head) {
    if (head == nullptr) return head;
    ListNode<int> *curr;
    curr = head;

    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            ListNode<int> *tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        } else curr = curr->next;
    }

    return head;
}
