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

ListNode* alternate(ListNode* a, ListNode* b) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = NULL;
	ListNode* c = p;
	int count = 0;
	while (a != NULL && b != NULL) {
		if (count % 2 == 0) {//count�� ¦���϶� a�߰�
			p->link = a;
			a = a->link;
			p = p->link;
		}
		else if (count % 2 == 1) {//count�� Ȧ�� �϶� b �߰�
			p->link = b;
			b = b->link;
			p = p->link;
		}
		count++;
	}
	if (a != NULL) {
		p->link = a;
	}
	else if (b != NULL) {
		p->link = b;
	}
	return c;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

int main(void) {
	ListNode* a = NULL;
	ListNode* b = NULL;
	ListNode* c = NULL;
	for (int i = 0; i < 3; i++) {
		a = insert_first(a, 3 - i); //insert_first���� ���� �ڷ� ������ ������ 3 - i�� �ۼ���
	}
	for (int i = 0; i < 5; i++) {
		b = insert_first(b, 5 - i);
	}

	c = alternate(a, b);

	print_list(c);
	return 0;
}