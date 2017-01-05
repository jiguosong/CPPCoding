/*
 * wordladder.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "wordladder.h"
#include <unordered_map>
#include <queue>

using std::unordered_map;
using std::queue;

/* Idea: BFS */
int solution::ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
{
	unordered_map<string, int> map;
	queue<string> queue;
	map[beginWord] = 1;
	queue.push(beginWord);

	while(!queue.empty()) {
		string word = queue.front();
		queue.pop();
		for(unsigned int i = 0; i < word.size(); ++i) {
			string newword = word;
			for(char c = 'a'; c <= 'z'; ++c) {
				newword[i] = c;
				if(newword == endWord) return map[word]+1;
				if(wordDict.find(newword) != wordDict.end() && map.find(newword) == map.end()) {
					queue.push(newword);
					map[newword] = map[word] + 1;
				}
			}
		}
	}

	return 0;
}

