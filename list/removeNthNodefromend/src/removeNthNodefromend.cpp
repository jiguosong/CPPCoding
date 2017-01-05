/*

*/

#include "removeNthNodefromend.h"

void removeNthNodefromend::dummy() {
}

ListNode<int> *removeNthNodefromend::removeNthFromEnd(ListNode<int> *head, int n) {
    if (head == nullptr || n <= 0) return head;

    ListNode<int> *fast, *slow;
    fast = slow = head;
    int cnt = 0;
    while (fast && cnt++ < n) fast = fast->next;
    if (fast == nullptr) return head->next;
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;
}