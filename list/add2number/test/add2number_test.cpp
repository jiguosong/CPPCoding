/*
 * add2number_test.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: songjiguo
 */

#include "gtest/gtest.h"
#include "../src/add2number.h"

#include "List.h"

TEST(test_case1, addTwoNumbers) {
	solution c;

	ListNode<int> *l1 = GetNode(2, GetNode(4, GetNode(3)));
	ListNode<int> *l2 = GetNode(5, GetNode(6, GetNode(4)));
	ListNode<int> *l3 = GetNode(7, GetNode(0, GetNode(8)));

	ListNode<int> *tmp = c.addTwoNumbers(l1, l2);

	for(int i = 0; i < 3; i++) {
		EXPECT_EQ(tmp->data, l3->data);
		tmp = tmp->next;
		l3 = l3->next;
	}
}

int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
}



