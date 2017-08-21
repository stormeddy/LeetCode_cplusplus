//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.


#include<stddef.h>
#include<limits>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class ReverseLinkedList {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode fh = ListNode(INT_MIN);
		fh.next = head;
		ListNode *p = head, *pre = &fh, *t, *start = NULL, *end = NULL;
		bool flag = true;
		while (p)
		{
			if (p->val < x)
			{
				if (start)
				{
					t = p->next;
					pre->next = p;
					p->next = start;
					pre = p;
					p = t;
					end->next = t;
				}
				else
				{
					pre = p;
					p = p->next;
				}

			}
			else
			{
				if (flag)
				{
					start = p;
					end = p;
					flag = false;
					p = p->next;
				}
				else
				{
					end = p;
					p = p->next;
				}

			}
		}
		return fh.next;




		/*ListNode *head1 = new ListNode(0);
		ListNode *head2 = new ListNode(0);
		ListNode *h1 = head1;
		ListNode *h2 = head2;
		while (head)
		{
			int v = head->val;
			if (v < x)
			{
				head1->next = head;
				head1 = head1->next;
			}
			else {
				head2->next = head;
				head2 = head2->next;
			}
			head = head->next;
		}
		head2->next = NULL;
		head1->next = h2->next;;
		return h1->next;*/
	}
};