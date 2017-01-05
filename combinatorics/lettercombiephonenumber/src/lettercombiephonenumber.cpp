/*

 Given a digit string, return all possible letter combinations that the number
 could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below.
 http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png?_=4452220

 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 Note:
 Although the above answer is in lexicographical order, your answer could be in
 any order you want.

 */

#include "lettercombiephonenumber.h"

void lettercombiephonenumber::dummy()
{
}

#include <iostream>

static void helper(std::string &digits, int level, std::string &tmp,
		vector<std::string> &res, vector<std::string> &dict)
{
	if (tmp.size() == digits.size()) {
		res.push_back(tmp);
		return;
	}

	int idx = digits[level] - '0';
	std::string s = dict[idx];
	for (int j = 0; j < s.size(); ++j) {
		tmp.push_back(s[j]);
		helper(digits, level + 1, tmp, res, dict);
		tmp.pop_back();
	}

}

vector<std::string> lettercombiephonenumber::letterCombinations(
		std::string digits)
{
	vector<std::string> dict = {"_", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs",
			"tuv", "wxyz" };

	vector<std::string> res;
	std::string tmp = "";
	helper(digits, 0, tmp, res, dict);
	return res;
}
