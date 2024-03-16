#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct  ListNode* link;
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

ListNode* search(ListNode* L, element data) {
	ListNode* p;

	if (L == NULL) return;
	p = L->link;
	do {
		if (p->data == data)
			return p;
		p = p->link;
	} while (p != L->link);
	fprintf(stderr, "검색오류\n");
	exit(1);
}

void print(ListNode* head) {
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}

int main(void) {
	ListNode* head = NULL;

	head = insert_first(head, 1);
	head = insert_first(head, 2);
	head = insert_first(head, 3);

	printf("1번째 %d\n", search(head, 2)->data);
	printf("2번째 %d\n", search(head, 4)->data);
	return 0;
}