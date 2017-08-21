//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class ReverseNodesink_Group {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *p = head, *pre = NULL, *t, *pp, *tail;
		ListNode fh = ListNode(0);
		fh.next = head;
		pp = &fh;
		int i;
		while (p)
		{
			i = k;
			tail = p;
			pre = NULL;
			while (p && i>0)
			{
				//reverse k-groups
				t = p->next;
				p->next = pre;
				pre = p;
				p = t;
				--i;
			}
			if (i == 0)
			{
				//concatenate groups
				pp->next = pre;
				tail->next = p;
				pp = tail;
			}
			else
			{
				//undo reverse
				p = pre;
				pre = NULL;
				while (p)
				{
					t = p->next;
					p->next = pre;
					pre = p;
					p = t;
				}
				pp->next = pre;
			}
		}
		return fh.next;


		/*-1 -> 1 -> 2 -> 3 -> 4 -> 5
		 |    |    |    | 
		pre  cur  nex  tmp

		-1 -> 2 -> 1 -> 3 -> 4 -> 5
		 |         |    |    | 
		pre       cur  nex  tmp

		-1 -> 3 -> 2 -> 1 -> 4 -> 5
		 |              |    |    | 
		pre            cur  nex  tmp
		Above is how it works inside one group iteration(for example, k=3)*/

		//if (head == NULL || k == 1) return head;
		//int num = 0;
		//ListNode *preheader = new ListNode(-1);
		//preheader->next = head;
		//ListNode *cur = preheader, *nex, *tmp, *pre = preheader;
		//while (cur = cur->next)
		//	num++;
		//while (num >= k) {
		//	cur = pre->next;
		//	nex = cur->next;
		//	for (int i = 1; i<k; i++) {
		//		tmp = nex->next;
		//		nex->next = pre->next;
		//		pre->next = nex;
		//		cur->next = tmp;
		//		nex = tmp;
		//	}
		//	pre = cur;
		//	num -= k;
		//}
		//return preheader->next;




		////no need for tmp
		//if (head == NULL || k == 1) return head;
		//int num = 0;
		//ListNode *preheader = new ListNode(-1);
		//preheader->next = head;
		//ListNode *cur = preheader, *nex, *pre = preheader;
		//while (cur = cur->next)
		//	num++;
		//while (num >= k) {
		//	cur = pre->next;
		//	nex = cur->next;
		//	for (int i = 1; i<k; ++i) {
		//		cur->next = nex->next;
		//		nex->next = pre->next;
		//		pre->next = nex;
		//		nex = cur->next;
		//	}
		//	pre = cur;
		//	num -= k;
		//}
		//return preheader->next;
	}
};