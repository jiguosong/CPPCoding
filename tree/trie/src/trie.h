#ifndef trie_H_
#define trie_H_

#include <unordered_map>
#include <string>
#include <vector>
using std::vector;
using std::unordered_map;

class trieNode {
public:
	trieNode *child[26];   // 26 letters
	unordered_map<char, trieNode *> child_map;
	bool isWord;
	trieNode(): isWord(false), child_map() {
		for(auto a:child) a = nullptr;
	}
};

class trie {
public:
	void dummy();
	trie();
	virtual ~trie(){}

	void insert(std::string word);
	bool search(std::string key);
	bool startWith(std::string prefix);
private:
	trieNode *root;
};

#endif
