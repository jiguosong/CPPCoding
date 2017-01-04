/*
 * pathsum.h
 *
 *  Created on: Nov 30, 2016
 *      Author: songjiguo
 */

#ifndef PATHSUM_H_
#define PATHSUM_H_

#include "../Tree.h"
#include <vector>
using std::vector;

class pathsum {
public:
	  bool hasPathSum(TreeNode *root, int sum);
	  vector<vector<int> > allpathSum(TreeNode *root, int sum);
};

#endif /* PATHSUM_H_ */
