//Given a singly linked list, determine if it is a palindrome.
//
//Follow up :
//Could you do it in O(n) time and O(1) space ?

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class PalindromeLinkedList {
public:
	bool isPalindrome(ListNode* head) {
		ListNode *slow = head, *fast = head;
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast)
		{
			slow = slow->next;
		}
		slow = reverse(slow);
		while (slow)
		{
			if (slow->val == head->val)
			{
				slow = slow->next;
				head = head->next;
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	ListNode* reverse(ListNode* h){
		ListNode* pre = NULL;
		ListNode* t = NULL;
		while (h){
			t = h->next;
			h->next = pre;
			pre = h;
			h = t;
		}
		return pre;
	}
};