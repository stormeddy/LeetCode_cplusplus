//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//Note: Do not modify the linked list.
//
//Follow up:
//Can you solve it without using extra space?

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class LinkedListCycle {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return NULL;

		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *entry = head;

		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {                      // there is a cycle
				while (slow != entry) {               // found the entry location
					slow = slow->next;
					entry = entry->next;
				}
				return entry;
			}
		}
		return NULL;
	}
};