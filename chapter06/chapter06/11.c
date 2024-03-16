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

int sum_list(ListNode* head) {
	int sum = 0;
	for (ListNode* p = head; p != NULL; p = p->link) //p = head�� ���� insert_first()�� 5, 6, 7 �� �����Ű�� head�� data�� 5�̱� ����
		sum += p->data;
	return sum;
}

int main(void) {
	int num;
	ListNode* head = NULL;
	
	printf("����� ���� : ");
	scanf_s("%d", &num);
	int* value = (int*)malloc(num * sizeof(int));

	for (int i = 0; i < num; i++) {
		printf("��� #%d ������ : ", i + 1);
		scanf_s("%d", &value[i]);
	}
	for (int i = 0; i < num; i++) {
		head = insert_first(head, value[num - 1 - i]);
	}

	printf("���� ����Ʈ�� ������ ��: %d", sum_list(head));
	return 0;
}