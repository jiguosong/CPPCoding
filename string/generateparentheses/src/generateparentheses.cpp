/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 "((()))", "(()())", "(())()", "()(())", "()()()"
 */

#include "generateparentheses.h"

void generateparentheses::dummy()
{
}

static void helper(int left, int right, string level, vector<string> &res)
{
	if (left < 0 || right < 0)
		return;
	if (left > right)
		return;
	if (left == 0 && right == 0)
		res.push_back(level);
	else {
		helper(left - 1, right, level + "(", res);
		helper(left, right - 1, level + ")", res);
	}
}

vector<string> generateparentheses::generateParentheses(int n)
{
	vector<string> res;
	string level = "";
	helper(n, n, level, res);
	return res;
}
