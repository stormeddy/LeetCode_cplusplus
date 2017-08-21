//Given a singly linked list L: L0��L1������Ln-1��Ln,
//reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2����
//
//You must do this in-place without altering the nodes' values.
//
//For example,
//Given {1,2,3,4}, reorder it to {1,4,2,3}.

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class ReorderList {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next) return;
		ListNode *p1 = head, *p2 = head;
		//split at mid
		while (p2&&p2->next)
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}
		ListNode* mid = p1->next;
		p1->next = NULL;

		//reverse list
		p1 = NULL;
		p2 = mid;
		ListNode *t;
		while (p2)
		{
			t = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = t;
		}

		//merge
		p2 = p1;
		p1 = head;
		while (p2)
		{
			t = p1->next;
			p1->next = p2;
			p1 = p2;
			p2 = t;
		}





		//if (!head || !head->next) return;

		//// find the middle node: O(n)
		//ListNode *p1 = head, *p2 = head->next;
		//while (p2 && p2->next) {
		//	p1 = p1->next;
		//	p2 = p2->next->next;
		//}

		//// cut from the middle and reverse the second half: O(n)
		//ListNode *head2 = p1->next;
		//p1->next = NULL;

		//p2 = head2->next;
		//head2->next = NULL;
		//while (p2) {
		//	p1 = p2->next;
		//	p2->next = head2;
		//	head2 = p2;
		//	p2 = p1;
		//}

		//// merge two lists: O(n)
		//ListNode *t;
		//for (p1 = head, p2 = head2; p1;) {
		//	t = p1->next;
		//	p1 = p1->next = p2;
		//	p2 = t;
		//}
	}
};