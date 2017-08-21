//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class ConstructBinaryTreefromPreorderandInorderTraversal {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return help(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* help(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
		if (ps > pe || is > ie) return NULL;
		TreeNode* r = new TreeNode(preorder[ps]);
		int pos = 0;
		for (int i = is; i <= ie; ++i){
			if (inorder[i] == preorder[ps]){
				pos = i;
				break;
			}
		}
		r->left = help(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
		r->right = help(preorder, inorder, ps + pos - is + 1, pe, pos + 1, ie);
		return r;
	}
};