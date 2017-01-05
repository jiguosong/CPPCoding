/*
 Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

 Note:

 The length of num is less than 10002 and will be ≥ k.
 The given num does not contain any leading zero.
 Example 1:

 Input: num = "1432219", k = 3
 Output: "1219"
 Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

 Example 2:

 Input: num = "10200", k = 1
 Output: "200"
 Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

 Example 3:

 Input: num = "10", k = 2
 Output: "0"
 Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 */
#include "removekdigits.h"

#include <iostream>

template<typename T, typename N>
T removekdigits::removeKdigits2(T num, N k)
{
	if (k <= 0)
		return num;

	T res = "";
	int resize = num.size() - k;
	for (char c : num) {
		if (k > 0 && res.size() && res.back() > c) {
			res.pop_back();
			k--;
		}
		res.push_back(c);
	}
	res.resize(resize);
	while (!res.empty() && res[0] == '0')
		res.erase(res.begin());
	return res.empty() ? "0" : res;
}


string removekdigits::removeKdigits(string num, int k)
{
	std::string s = "10934097";
	int kk = 2;
	std::string tmp_ans = removeKdigits2<std::string, int>(s, kk);
	std::cout << tmp_ans << std::endl;

	if (k <= 0)
		return num;

	string res = "";
	int resize = num.size() - k;
	for (char c : num) {
		if (k > 0 && res.size() && res.back() > c) {
			res.pop_back();
			k--;
		}
		res.push_back(c);
	}
	res.resize(resize);
	while (!res.empty() && res[0] == '0')
		res.erase(res.begin());
	return res.empty() ? "0" : res;
}
