/*
Problem:

    Choose k entries from n numbers. Make sure each number is selected with the probability of k/n

Basic idea:

    Choose 1, 2, 3, ..., k first and put them into the reservoir.
    For k+1, pick it with a probability of k/(k+1), and randomly replace a number in the reservoir.
    For k+i, pick it with a probability of k/(k+i), and randomly replace a number in the reservoir.
    Repeat until k+i reaches n

Proof:

    For k+i, the probability that it is selected and will replace a number in the reservoir is k/(k+i)
    For a number in the reservoir before (let's say X), the probability that it keeps staying in the reservoir is
        P(X was in the reservoir last time) × P(X is not replaced by k+i)
        = P(X was in the reservoir last time) × (1 - P(k+i is selected and replaces X))
        = k/(k+i-1) × （1 - k/(k+i) × 1/k）
        = k/(k+i)
    When k+i reaches n, the probability of each number staying in the reservoir is k/n

Example

    Choose 3 numbers from [111, 222, 333, 444]. Make sure each number is selected with a probability of 3/4
    First, choose [111, 222, 333] as the initial reservior
    Then choose 444 with a probability of 3/4
    For 111, it stays with a probability of
        P(444 is not selected) + P(444 is selected but it replaces 222 or 333)
        = 1/4 + 3/4*2/3
        = 3/4
    The same case with 222 and 333
    Now all the numbers have the probability of 3/4 to be picked
*/

#include "resorvoirsampling.h"

void resorvoirsampling::dummy() 
{

}

#include <random>
#include <iostream>
int resorvoirsampling::getrandom_reservoir(ListNode<int> *head)
{
	if(head == nullptr) return -1;
	std::random_device rd;
	std::mt19937 gen(rd());

	int len = 0;
	int res = head->data;
	++len;
	ListNode<int> *v = head->next;
	while(v) {
		std::uniform_int_distribution<uint32_t> dist(0,len);  // inclusive
		unsigned int n = dist(gen);
		if(n == len) {
/*
			cout << "Yeah, slected!!!" << endl;
			cout << n << endl;
*/
			res = v->data;
		}
		++len;
		v = v->next;
	}
	return res;
}
