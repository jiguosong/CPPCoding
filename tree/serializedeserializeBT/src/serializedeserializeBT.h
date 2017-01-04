#ifndef serializedeserializeBT_H_
#define serializedeserializeBT_H_

#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>
using std::vector;

#include "../Tree.h"

class serializedeserializeBT
{
public:
	void dummy();
	std::string serialize(TreeNode* root);
	TreeNode* deserialize(std::string data);
private:
	void serialize(std::ostringstream &out, TreeNode *root);
	TreeNode *deserialize(std::istringstream &in);
};

#endif
