//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.


#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class SwapNodesinPairs {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode fh = ListNode(0);
		fh.next = head;
		ListNode *p = head, *pre = &fh, *t, *np;
		while (p&&p->next)
		{
			t = p->next;
			np = t->next;
			pre->next = t;
			t->next = p;
			p->next = np;
			pre = p;
			p = np;
		}
		return fh.next;


		/*ListNode **pp = &head, *a, *b;
		while ((a = *pp) && (b = a->next)) {
			a->next = b->next;
			b->next = a;
			*pp = b;
			pp = &(a->next);
		}
		return head;*/
	}
};