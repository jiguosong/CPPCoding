/*
 * parsestr2tree.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "parsestr2tree.h"
#include <stack>

using std::stack;

TreeNode *parserstr2tree::parserstrTotree(const string &str)
{
	string roots, lefts, rightsa, delimiter;
	TreeNode *root, *left, *right;
	int pos, found;

	// find roots
	delimiter = "name:";
	pos = str.find(delimiter);
	if(pos != -1) {
		roots = str.substr(pos+delimiter.length());
		found = roots.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
		if(found != -1) roots = roots.substr(0, found);
	}

	delimiter = "children:[";
	pos = str.find(delimiter);
	string child_s;
	if(pos != -1) {
		child_s = str.substr(pos+delimiter.length());
		found = child_s.find_last_of("]");
		if(found != -1) child_s = child_s.substr(0, found);
	}


	stack<char> stack;
	int idx = 0;
	for(char c:child_s) {
		if(c == '{' || c == '[') stack.push(c);
		if(c == '}' || c == ']') stack.pop();
		++idx;
		if(stack.empty()) break;
	}

	lefts = child_s.substr(0, idx);
	rightsa = child_s.substr(idx+2);

	parserstrTotree(rightsa);
	//parserstr2tree(rights);

	//root = new TreeNode(10);  // 10 -> roots
	//root->left = left;
	//root->right = right;

	return root;
}
