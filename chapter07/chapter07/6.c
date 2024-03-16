#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* rlink;
	struct ListNode* llink;
}ListNode;

void init(ListNode* phead) {
	phead->rlink = phead;
	phead->llink = phead;
}

void dinsert(ListNode* before, element data) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void print(ListNode* head) {
	for (ListNode* p = head->rlink; p != head; p = p->rlink) {
		printf(" %d", p->data);
	}
	printf("\n");
}

int main(void) {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	init(head);
	int num;
	int data;
	printf("�������� ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		printf("��� #%d�� �����͸� �Է��Ͻÿ�: ", i + 1);
		scanf_s("%d", &data);
		dinsert(head, data);
	}
	printf("�����͸� �������� ���: ");
	print(head);
	return 0;
}