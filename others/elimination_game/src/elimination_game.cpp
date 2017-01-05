/*
 There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.

 Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

 We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

 Find the last number that remains starting with a list of length n.

 Example:

 Input:
 n = 9,
 1 2 3 4 5 6 7 8 9
 2 4 6 8
 2 6
 6

 Output:
 6
 */

#include "elimination_game.h"

void elimination_game::dummy()
{
}

#include <iostream>
static int helper(int n, bool lefttoright)
{
	if(n == 1) return 1;
	if(lefttoright) return 2*helper(n/2, false);
	else return 2*helper(n/2, true) -1 + n%2;
}

int elimination_game::lastRemaining(int n)
{
	return helper(n, true);
}
