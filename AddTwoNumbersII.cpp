//You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Follow up:
//What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
//
//Example:
//
//Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 8 -> 0 -> 7

#include<stddef.h>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class AddTwoNumbersII {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		vector<int> m1, m2;
		int n1 = 0, n2 = 0;
		while (l1)
		{
			++n1;
			m1.push_back(l1->val);
			l1 = l1->next;
		}
		while (l2)
		{
			++n2;
			m2.push_back(l2->val);
			l2 = l2->next;
		}
		int cin = 0;
		ListNode* t = NULL;
		for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0 || cin; --i, --j)
		{
			int sum = 0;
			if (i >= 0)
			{
				sum += m1[i];
			}
			if (j >= 0)
			{
				sum += m2[j];
			}
			sum += cin;
			ListNode* cur = new ListNode(sum % 10);
			cin = sum / 10;
			cur->next = t;
			t = cur;
		}
		return t;
	}





	// (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
	//=> 7 -> 10 -> 7 -> 7
	//=> 7 -> 8 -> 0 -> 7
	/*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int n1 = 0, n2 = 0, carry = 0;
		ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
		while (curr1){ curr1 = curr1->next; n1++; }
		while (curr2){ curr2 = curr2->next; n2++; }
		curr1 = l1; curr2 = l2;
		while (n1 > 0 && n2 > 0){
			int sum = 0;
			if (n1 >= n2){ sum += curr1->val; curr1 = curr1->next; n1--; }
			if (n2 > n1){ sum += curr2->val; curr2 = curr2->next; n2--; }
			res = addToFront(sum, res);
		}
		curr1 = res; res = NULL;
		while (curr1){
			curr1->val += carry; carry = curr1->val / 10;
			res = addToFront(curr1->val % 10, res);
			curr2 = curr1;
			curr1 = curr1->next;
			delete curr2;
		}
		if (carry) res = addToFront(1, res);
		return res;
	}

	ListNode* addToFront(int val, ListNode* head){
		ListNode* temp = new ListNode(val);
		temp->next = head;
		return temp;
	}*/
};