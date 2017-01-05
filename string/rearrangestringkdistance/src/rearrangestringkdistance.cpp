/*
 Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

 All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

 Example 1:

 str = "aabbcc", k = 3

 Result: "abcabc"

 The same letters are at least distance 3 from each other.

 Example 2:

 str = "aaabc", k = 3

 Answer: ""

 It is not possible to rearrange the string.

 Example 3:

 str = "aaadbbcc", k = 2

 Answer: "abacabcd"

 Another possible answer is: "abcabcda"

 The same letters are at least distance 2 from each other.

 */

#include "rearrangestringkdistance.h"
#include <unordered_map>
#include <queue>
#include <iostream>

void rearrangestringkdistance::dummy()
{
}

std::string rearrangestringkdistance::rearrangeStringKDistance(std::string &str,
		int k)
{
	std::unordered_map<char, int> map;
	for(auto c : str) ++map[c];

	std::priority_queue<std::pair<int, char>> queue;
	for(auto it = map.begin(); it != map.end(); ++it) {
		queue.push({it->second, it->first});
	}

	int len = str.size();
	std::string res = "";

	while(!queue.empty()) {
		vector<std::pair<int, char>> v;
		int cnt = std::min(len, k);
		for(int i = 0; i < cnt; ++i) {
			if(queue.empty()) return "";
			auto t = queue.top(); queue.pop();
			res += t.second;
			//res.push_back(t.second);
			if(--t.first != 0) v.push_back(t);
			--len;
		}
		for(auto e:v) queue.push(e);
	}

	return res;
}
