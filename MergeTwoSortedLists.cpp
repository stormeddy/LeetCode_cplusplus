//Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class MergeTwoSortedLists {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode h(0);
		ListNode* pre = &h;
		while (l1&&l2)
		{
			if (l1->val<l2->val)
			{
				pre->next = l1;
				l1 = l1->next;
			}
			else
			{
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}
		if (l1)
		{
			pre->next = l1;
		}
		else
		{
			pre->next = l2;
		}
		return h.next;


		//recursive
		/*if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}*/
	}
};