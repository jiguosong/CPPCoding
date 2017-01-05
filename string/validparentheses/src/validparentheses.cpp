/*

 Given a string containing just the characters
 '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all
 valid but "(]" and "([)]" are not.

 */

#include "validparentheses.h"

#include <stack>

void validparentheses::dummy()
{
}

bool validparentheses::validParentheses(string &str)
{
	std::stack<char> stk;
	for (auto c : str) {
		if (c == '(' || c == '{' || c == '[')
			stk.push(c);
		else if (c == ')' || c == '}' || c == ']') {
			if (stk.empty())
				return false;
			else {
				if(c == ')' && stk.top()!= '(') return false;
				else if(c == '}' && stk.top()!= '{') return false;
				else if(c == ']' && stk.top()!= '[') return false;
				stk.pop();
			}
		}
	}

	return stk.empty();

}
