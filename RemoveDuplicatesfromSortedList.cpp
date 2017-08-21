//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class RemoveDuplicatesfromSortedList {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* h = new ListNode(0);
		h->next = head;
		ListNode *pre = h, *cur = head, *tmp = NULL;
		while (cur)
		{
			if (cur->val == val)
			{
				tmp = cur;
				pre->next = cur->next;
				cur = cur->next;
				delete tmp;
			}
			else
			{
				pre = pre->next;
				cur = cur->next;
			}
		}
		return h->next;
	}
};