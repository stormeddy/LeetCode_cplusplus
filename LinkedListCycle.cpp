//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class LinkedListCycle {
public:
	bool hasCycle(ListNode *head) {

		ListNode *slow = head, *fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) return true;
		}
		return false;
	}
};