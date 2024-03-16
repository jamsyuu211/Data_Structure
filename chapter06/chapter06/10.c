#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* create() {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = NULL;
	p->link = NULL;
	return p;
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int count_list(ListNode* head) {
	int count = 0;
	for (ListNode* p = head->link; p != NULL; p = p->link) { //p = head->link�� ����) head�� ����� ����Ʈ�� ������ ��ȯ�ؾ� �ϹǷ�
		count++;
	}
	return count;
}

int main(void) {
	ListNode* head = create();
	int num;
	printf("����� ���� : ");
	scanf_s("%d", &num);
	element* value = (element*)malloc(num * sizeof(element));

	for (int i = 0; i < num; i++) {
		printf("��� #%d ������ : ", i + 1);
		scanf_s("%d", &value[i]);
	}
	for (int i = 0; i < num; i++) {
		head = insert_first(head, value[num - 1 - i]);
	}
	printf("���� ����Ʈ ����� ���� = %d", count_list(head));
	return 0;
}