//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists:
//
//A:          a1 ¡ú a2
//                   ¨K
//                     c1 ¡ú c2 ¡ú c3
//                   ¨J            
//B:     b1 ¡ú b2 ¡ú b3
//begin to intersect at node c1.
//
//
//Notes:
//
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.

#include<stddef.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class IntersectionofTwoLinkedLists {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *l1 = headA, *l2 = headB;
		int n1 = 0, n2 = 0, diff = 0;
		while (l1)
		{
			++n1;
			l1 = l1->next;
		}
		while (l2)
		{
			++n2;
			l2 = l2->next;
		}
		l1 = headA;
		l2 = headB;
		if (n1 > n2)
		{
			diff = n1 - n2;
			while (diff)
			{
				l1 = l1->next;
				--diff;
			}
		}
		else
		{
			diff = n2 - n1;
			while (diff)
			{
				l2 = l2->next;
				--diff;
			}
		}
		while (l1&&l2)
		{
			if (l1 == l2) return l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		return NULL;
	}


	//better and elegant

	//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	//	ListNode *p1 = headA;
	//	ListNode *p2 = headB;

	//	if (p1 == NULL || p2 == NULL) return NULL;

	//	while (p1 != NULL && p2 != NULL && p1 != p2) {
	//		p1 = p1->next;
	//		p2 = p2->next;

	//		//
	//		// Any time they collide or reach end together without colliding 
	//		// then return any one of the pointers.
	//		//
	//		if (p1 == p2) return p1;

	//		//
	//		// If one of them reaches the end earlier then reuse it 
	//		// by moving it to the beginning of other list.
	//		// Once both of them go through reassigning, 
	//		// they will be equidistant from the collision point.
	//		//
	//		if (p1 == NULL) p1 = headB;
	//		if (p2 == NULL) p2 = headA;
	//	}

	//	return p1;
	//}

};