//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.


#include<stddef.h>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class ConvertSortedArraytoBinarySearchTree {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return NULL;
		return help(nums, 0, nums.size() - 1);

	}

	TreeNode* help(vector<int>& nums, int i, int j){
		if (i>j) return NULL;
		if (i == j) return new TreeNode(nums[i]);
		int mid = i + (j - i) / 2;
		TreeNode* r = new TreeNode(nums[mid]);
		r->left = help(nums, i, mid - 1);
		r->right = help(nums, mid + 1, j);
		return r;
	}
};