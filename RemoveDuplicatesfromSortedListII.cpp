//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.

#include<stddef.h>
#include<climits>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class RemoveDuplicatesfromSortedListII {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return head;
		ListNode h = ListNode(INT_MAX);
		h.next = head;
		ListNode *pre = &h, *cur_h = head, *cur = head->next;
		while (cur)
		{
			if (cur_h->val != cur->val)
			{
				pre = pre->next;
				cur_h = cur_h->next;
				cur = cur->next;
			}
			else
			{
				while (cur&&cur->val == cur_h->val)
				{
					ListNode *t = cur;
					cur = cur->next;
					delete t;
				}
				delete cur_h;
				pre->next = cur;
				cur_h = cur;
				if (!cur) break;
				cur = cur->next;

			}
		}
		return h.next;




		//no fake head
		/*ListNode **runner = &head;

		if (!head || !head->next)return head;

		while (*runner)
		{
			if ((*runner)->next && (*runner)->next->val == (*runner)->val)
			{
				ListNode *temp = *runner;
				while (temp && (*runner)->val == temp->val)
					temp = temp->next;

				*runner = temp;
			}
			else
				runner = &((*runner)->next);
		}

		return head;*/
	}
};