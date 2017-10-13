#include "stdio.h"
#include "stdlib.h"

// Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	struct ListNode *head, *temp;
	if (l1->val <= l2->val) {
		temp = l1;
		l1 = l1->next;
	}
	else {
		temp = l2;
		l2 = l2->next;
	}
	head = temp;
	while (l1 != NULL && l2 != NULL) {
		if (l1->val < l2->val) {
			temp->next = l1;
			l1 = l1->next;
		}
		else {
			temp->next = l2;
			l2 = l2->next;
		}
		temp = temp->next;
	}
	if (l1 == NULL) {
		temp->next = l2;
	}
	else {
		temp->next = l1;
	}
	return head;
}

//int main() {
//	
//}