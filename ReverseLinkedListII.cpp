//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note:
//Given m, n satisfy the following condition:
//1 ¡Ü m ¡Ü n ¡Ü length of list.


#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class ReverseLinkedListII {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		ListNode fh = ListNode(0);
		fh.next = head;
		int i = 1;
		ListNode *pre = &fh;
		while (i<m)
		{
			++i;
			pre = pre->next;
		}
		ListNode *h = pre->next, *cur = pre->next, *tmp, *t;
		while (i <= n)
		{
			tmp = cur->next;
			cur->next = t;
			t = cur;
			cur = tmp;
			++i;
		}
		pre->next = t;
		h->next = cur;
		return fh.next;

	}
};