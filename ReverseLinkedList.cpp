//Reverse a singly linked list.
//
//click to show more hints.
//
//Hint:
//A linked list can be reversed either iteratively or recursively.Could you implement both ?


#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class ReverseLinkedList {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL, *nex = NULL;
		while (head) {
			nex = head->next;
			head->next = pre;
			pre = head;
			head = nex;
		}
		return pre;

		//recursive
		/*if (!head || !(head->next)) return head;
		ListNode* node = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return node;*/
	}
};