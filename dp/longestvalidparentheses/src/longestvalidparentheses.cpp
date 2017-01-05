/*

 Given a string containing just the characters '(' and ')',
 find the length of the longest valid (well-formed) parentheses
 substring.

 For "(()", the longest valid parentheses substring is "()",
 which has length = 2. Another example is ")()())", where the longest
 valid parentheses substring is "()()", which has length = 4.
 */

#include "longestvalidparentheses.h"

#include <stack>

void longestvalidparentheses::dummy()
{
}

int longestvalidparentheses::longestValidParentheses(string s)
{
	int res = 0;

	/*
	 vector<int> dp(s.size() + 1, 0);
	 for (int i = 1; i <= s.size(); ++i) {
	 int j = i - dp[i - 1] - 2;
	 if (s[i - 1] == ')' && j >= 0 && s[j] == '(')
	 dp[i] = dp[i - 1] + 2 + dp[j];
	 else
	 dp[i] = 0;
	 res = std::max(res, dp[i]);
	 }
	 */

	std::stack<int> stk;
	int left = 0;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if (c == '(')
			stk.push(i);
		else {
			if (stk.empty())   // we just examed a complete valid parentheses
				left = i + 1;
			else {
				stk.pop();
				if (stk.empty())
					res = std::max(res, i - left + 1);
				else
					res = std::max(res, i - stk.top() + 1);
			}
		}
	}

	return res;
}
