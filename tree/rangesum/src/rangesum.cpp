

#include "rangesum.h"

struct TreeNode
{
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	int tree_size = 1;
	long long value = 0;
};

TreeNode *InsertToBST(TreeNode *root, long long value) {
	if (root == nullptr) {
		auto node = new TreeNode;
		node->value = value;
		return node;
	}

	if (value < root->value) {
		root->left = InsertToBST(root->left, value);
	} else {
		root->right = InsertToBST(root->right, value);
	}
	++root->tree_size;
	return root;
}

int CountGEQ(TreeNode *root, long long hint) {
	// recursive version.
	// if (root == nullptr) {
	//     return 0;
	// }
	//
	// if (root->value < hint) {
	//     return CountGEQ(root->right, hint);
	// } else if (root->value == hint) {
	//     return root->tree_size - (root->left?
	//     root->left->tree_size : 0);
	// } else {
	//     int right_subtree_size = root->right?
	//     root->right->tree_size : 0;
	//     return right_subtree_size + 1 +
	//     CountGEQ(root->left, hint);
	// }

	// iterative version, reduce 40ms.
	int count = 0;
	while (root != nullptr) {
		if (root->value < hint) {
			root = root->right;
		} else if (root->value == hint) {
			count += root->tree_size;
			count -= root->left ? root->left->tree_size : 0;
			break;
		} else {
			count += root->right ? root->right->tree_size : 0;
			count += 1;
			root = root->left;
		}
	}
	return count;
}


int CountRange(TreeNode *root, long long lower_bound, long long upper_bound) {
	return CountGEQ(root, lower_bound) - CountGEQ(root, upper_bound);
}


vector<long long> BuildPrefixSum(const vector<int> &nums) {
	vector<long long> prefix_sums(nums.size() + 1, 0);
	for (int i = 1; i <= nums.size(); ++i) {
		prefix_sums[i] = prefix_sums[i - 1] + nums[i - 1];
	}
	return prefix_sums;
}

int rangesum::countRangeSum(vector<int> &nums, int lower, int upper)
{
	if (nums.empty()) {
		return 0;
	}
	const int n = nums.size();

	auto prefix_sums = BuildPrefixSum(nums);

	TreeNode *root = nullptr;
	int count = 0;
	for (int i = n; i >= 1; --i) {
		root = InsertToBST(root, prefix_sums[i]);
		count += CountRange(root, prefix_sums[i - 1] + lower,
				prefix_sums[i - 1] + upper + 1);
	}
	return count;
}


