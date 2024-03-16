#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = value;

	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

int get_size(ListNode* L) {
	int count = 0;
	if (L == NULL) {
		return 0;
	}
	ListNode* p;
	p = L->link;
	
	do {
		count++;
		p = p->link;
	} while (p != L->link);
	return count;
}

int main(void) {
	ListNode* head = NULL;

	head = insert_first(head, 1);
	head = insert_first(head, 2);
	head = insert_first(head, 3);

	printf("¸®½ºÆ® °¹¼ö : %d\n", get_size(head));
	return 0;
}