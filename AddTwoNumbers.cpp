//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class AddTwoNumbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* h = new ListNode(0);
		ListNode* pre = h;
		int cin = 0;
		while (l1&&l2)
		{
			ListNode* t = new ListNode((l1->val + l2->val + cin) % 10);
			pre->next = t;
			pre = t;
			cin = (l1->val + l2->val + cin) / 10;
			l1 = l1->next; l2 = l2->next;
		}
		if (l1)
		{
			while (l1)
			{
				ListNode* t = new ListNode((l1->val + cin) % 10);
				pre->next = t;
				pre = t;
				cin = (l1->val + cin) / 10;
				l1 = l1->next;
			}
		}

		if (l2)
		{
			while (l2)
			{
				ListNode* t = new ListNode((l2->val + cin) % 10);
				pre->next = t;
				pre = t;
				cin = (l2->val + cin) / 10;
				l2 = l2->next;
			}
		}
		if (cin)
		{
			ListNode* t = new ListNode(cin);
			pre->next = t;
		}
		return h->next;
	}
};