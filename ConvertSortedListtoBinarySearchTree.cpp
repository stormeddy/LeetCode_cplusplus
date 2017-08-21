//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class ConvertSortedListtoBinarySearchTree {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return help(head, NULL);
	}

	TreeNode* help(ListNode* head, ListNode* tail){
		if (head == tail)
		{
			return NULL;
		}
		if (head->next == tail)
		{
			return new TreeNode(head->val);
		}
		ListNode *mid = head, *tmp = head;
		while (tmp != tail&&tmp->next != tail)
		{
			mid = mid->next;
			tmp = tmp->next->next;
		}
		TreeNode *r = new TreeNode(mid->val);
		r->left = help(head, mid);
		r->right = help(mid->next, tail);
		return r;
	}
};