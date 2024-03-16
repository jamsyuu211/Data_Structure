#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void split(ListNode* head, ListNode** a, ListNode** b) {
	ListNode* p = head;
	ListNode* p_a = NULL;
	ListNode* p_b = NULL;
	int i = 0;
	while (p != NULL) {
		if (i % 2 == 0) {
			p_b = insert_first(p_b, p->data);
		}
		else if (i % 2 == 1) {
			p_a = insert_first(p_a, p->data);
		}
		p = p->link;
		i++;
	}
	ListNode* result_a = NULL;
	ListNode* result_b = NULL;
	for (; p_b != NULL; p_b = p_b->link) {
		result_b = insert_first(result_b, p_b->data);
	}
	for (; p_a != NULL; p_a = p_a->link) {
		result_a = insert_first(result_a, p_a->data);
	}
	*a = result_a;
	*b = result_b;
}

void print(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

int main(void) {
	ListNode* head = NULL;
	ListNode* a = NULL;
	ListNode* b = NULL;

	for (int i = 10; i >= 1; i--) {
		head = insert_first(head, i);
	}
	print(head);
	printf("\n");

	split(head, &a, &b);

	print(a);
	printf("\n");

	print(b);
	printf("\n");
	return 0;
}