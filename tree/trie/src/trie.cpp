/*
 Implement a trie with insert, search, and startsWith methods.

 Note:
 You may assume that all inputs are consist of lowercase letters a-z.
 */

#include "trie.h"

void trie::dummy()
{
}

trie::trie()
{
	root = new trieNode();
}

void trie::insert(std::string word)
{
	trieNode *p = root;
	for (auto a : word) {
		/*
		 int idx = a-'a';
		 if(!p->child[idx]) p->child[idx] = new trieNode();
		 else p = p->child[idx];
		 */

		if (p->child_map.count(a) == 0)
			p->child_map[a] = new trieNode();
		p = p->child_map[a];
	}
	p->isWord = true;
}

bool trie::search(std::string key)
{
	trieNode *p = root;
	for (auto a : key) {
		/*
		 int idx = a-'a';
		 if(!p->child[idx]) return false;
		 else p = p->child[idx];
		 */
		if (p->child_map.count(a) == 0)
			return false;
		p = p->child_map[a];
	}
	return p->isWord;
}

// Returns if there is any word in the trie
// that starts with the given prefix.
bool trie::startWith(std::string prefix)
{
	trieNode *p = root;
	for (auto a : prefix) {
		/*
		 int idx = a - 'a';
		 if (!p->child[idx])
		 return false;
		 else
		 p = p->child[idx];
		 */
		if (p->child_map.count(a) == 0)
			return false;
		p = p->child_map[a];
	}
	return true;
}

/*

 class TrieNode {
 public:
 bool is_word;
 unordered_map<char, TrieNode*> next;
 // Initialize your data structure here.
 TrieNode() : is_word(false), next() { }
 };

 class Trie {
 public:
 Trie() {
 root = new TrieNode();
 }

 // Free resources
 ~Trie() {
 destroy(root);
 }

 // Inserts a word into the trie.
 void insert(const string& s) {
 TrieNode* node = root;
 for (auto c: s) {
 if (node->next.count(c) == 0) node->next[c] = new TrieNode();
 node = node->next[c];
 }
 node->is_word = true;
 }

 // Returns if the word is in the trie.
 bool search(const string& key) {
 TrieNode* node = getNode(key);
 return node != nullptr && node->is_word;
 }

 // Returns if there is any word in the trie
 // that starts with the given prefix.
 bool startsWith(const string& prefix) {
 return getNode(prefix) != nullptr;
 }

 // Return the node if the key exists in the trie, nullptr otherwise
 TrieNode* getNode(const string& key) {
 TrieNode* node = root;
 for (auto c: key) {
 if (node->next.count(c) == 0) return nullptr;
 node = node->next[c];
 }
 return node;
 }

 private:
 TrieNode* root;

 // Free recources in post order
 void destroy(TrieNode* root) {
 for (auto node : root->next) {
 destroy(node.second);
 }
 delete root;
 }
 };

 // Your Trie object will be instantiated and called as such:
 // Trie trie;
 // trie.insert("somestring");
 // trie.search("key");*/
