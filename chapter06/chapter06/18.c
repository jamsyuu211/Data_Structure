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

ListNode* merge(ListNode* a, ListNode* b) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = -1;
	ListNode* c = p;
	while(a != NULL && b != NULL) {
		if (a->data < b->data) {
			p->link = a;
			a = a->link;
		}
		else if (a->data > b->data) {
			p->link = b;
			b = b->link;
		}
		else {
			p->link = a;
			a = a->link;

			p = p->link; //a¿¬°á ÈÄ b¿¬°á

			p->link = b;
			b = b->link;
		}
		p = p->link;
	}
	if (a != NULL) {
		p->link = a;
	}
	else if (b != NULL) {
		p->link = b;
	}

	return c;
}

void print(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

int main(void) {
	ListNode* a = NULL;
	ListNode* b = NULL;
	ListNode* head;

	for (int i = 2; i >= 0; i--) {
		a = insert_first(a, i);// 0, 1, 2 »ğÀÔ
	}
	for (int i = 4; i >= 1; i--) {
		b = insert_first(b, i);//1, 2, 3, 4 »ğÀÔ
	}

	head = merge(a, b);
	print(head);
	return 0;
}