//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//   Given linked list: 1->2->3->4->5, and n = 2.
//
//   After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//Given n will always be valid.
//Try to do this in one pass.

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class RemoveNthNodeFromEndofList {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode fh = ListNode(0);
		fh.next = head;
		ListNode *fast = head, *slow = &fh;
		int i = n;
		while (i)
		{
			fast = fast->next;
			--i;
		}
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return fh.next;



		/*ListNode** t1 = &head, *t2 = head;
		for (int i = 1; i < n; ++i)
		{
			t2 = t2->next;
		}
		while (t2->next != NULL)
		{
			t1 = &((*t1)->next);
			t2 = t2->next;
		}
		*t1 = (*t1)->next;
		return head;*/

	}
};