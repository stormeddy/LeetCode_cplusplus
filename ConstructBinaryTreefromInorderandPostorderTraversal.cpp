//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

#include<vector>

using namespace std;

#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};



class ConstructBinaryTreefromInorderandPostorderTraversal {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return help(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* help(vector<int>& postorder, vector<int>& inorder, int ps, int pe, int is, int ie){
		if (ps > pe || is > ie) return NULL;
		TreeNode* r = new TreeNode(postorder[pe]);
		int pos = 0;
		for (int i = is; i <= ie; ++i){
			if (inorder[i] == postorder[pe]){
				pos = i;
				break;
			}
		}
		r->left = help(postorder, inorder, ps, pe - ie + pos - 1, is, pos - 1);
		r->right = help(postorder, inorder, pe - ie + pos, pe - 1, pos + 1, ie);
		return r;
	}
};