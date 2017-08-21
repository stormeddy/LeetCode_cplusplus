//Given a list, rotate the list to the right by k places, where k is non-negative.
//
//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class RotateList {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return head;
		int i = 0;
		ListNode *p = head;
		while (p)
		{
			p = p->next;
			++i;
		}
		k = k%i;
		if (!k) return head;

		p = head;
		while (k)
		{
			p = p->next;
			--k;
		}
		ListNode *t = head;
		while (p->next)
		{
			p = p->next;
			t = t->next;
		}
		ListNode *res = t->next;
		t->next = NULL;
		p->next = head;
		return res;





		//if (!head) return head;

		//int len = 1; // number of nodes
		//ListNode *newH, *tail;
		//newH = tail = head;

		//while (tail->next)  // get the number of nodes in the list
		//{
		//	tail = tail->next;
		//	++len;
		//}
		//tail->next = head; // circle the link

		//if (k %= len)
		//{
		//	for (int i = 0; i<len - k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
		//}
		//newH = tail->next;
		//tail->next = NULL;
		//return newH;
	}
};