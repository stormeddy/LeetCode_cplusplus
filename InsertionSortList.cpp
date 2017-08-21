//Sort a linked list using insertion sort.

#include<stddef.h>
#include<climits>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class InsertionSortList {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head) return NULL;
		ListNode fh = ListNode(INT_MIN);
		fh.next = head;
		ListNode *pre = head, *cur = head, *t, *p, *nex;
		while (cur)
		{
			nex = cur->next;
			t = fh.next;
			p = &fh;
			while (t != cur&&t->val<cur->val)
			{
				t = t->next;
				p = p->next;
			}

			if (t != cur)
			{
				p->next = cur;
				cur->next = t;
				pre->next = nex;
			}
			else
			{
				pre = cur;
			}

			cur = nex;
		}
		return fh.next;







		//ListNode result(INT_MIN);
		////result.next=head;

		//while (head) {
		//	ListNode* iter = &result;
		//	while (iter->next && iter->next->val < head->val) {
		//		iter = iter->next;
		//	}
		//	ListNode* next = head->next;
		//	head->next = iter->next;
		//	iter->next = head;
		//	head = next;
		//}

		//return result.next;
	}
};