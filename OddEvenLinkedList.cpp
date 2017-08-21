//Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example:
//Given 1->2->3->4->5->NULL,
//return 1->3->5->2->4->NULL.
//
//Note:
//The relative order inside both the even and odd groups should remain as it was in the input. 
//The first node is considered odd, the second node even and so on ...

#include<stddef.h>
#include<climits>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class SortList {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *pre = head, *cur = head->next->next, *nex, *h = head->next, *t = head->next;
		bool f = true;
		while (cur)
		{
			if (f)
			{
				nex = cur->next;
				h = pre->next;
				pre->next = cur;
				cur->next = h;
				pre = cur;
				cur = nex;
				t->next = cur;
				f = !f;

			}
			else
			{
				f = !f;
				t = cur;
				cur = cur->next;
			}


		}
		return head;





		/*if (!head) return head;
		ListNode *odd = head, *evenhead = head->next, *even = evenhead;
		while (even && even->next)
		{
			odd->next = odd->next->next;
			even->next = even->next->next;
			odd = odd->next;
			even = even->next;
		}
		odd->next = evenhead;
		return head;*/
	}
};