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

element max_list(ListNode* head) {
	element max = head->data;
	for (ListNode* p = head; p != NULL; p = p->link) { //÷�̶� �������� 1���� �� ������ �� ����
		if (p->data > max)
			max = p->data;
	}
	return max;
}

element min_list(ListNode* head) {
	element min = head->data;
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data < min)
			min = p->data;
	}
	return min;
}

int main(void) {
	ListNode* head = NULL;

	for (int i = 0; i < 3; i++) {
		head = insert_first(head, i);
	}
	printf("�ִ� : %d\n", max_list(head));
	printf("�ּڰ� : %d\n", min_list(head));
	return 0;
}