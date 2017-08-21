//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5


#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class RemoveLinkedListElements {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;

		ListNode* cur = head;
		while (cur->next != NULL) {
			if (cur->val == cur->next->val) {
				cur->next = cur->next->next;
			}
			else cur = cur->next;
		}
		return head;
	}
};