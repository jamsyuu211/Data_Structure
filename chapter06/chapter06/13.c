#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
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

ListNode* delete(ListNode* head, element value) {
	for (ListNode* p = head; p != NULL;) { //�������� ������ �ؿ� if���� ��������� �ѹ��� �����Ǳ� ������ else������ �߰���
		if (p->data == value) {//p�� ������ �����ϹǷ� head���� �����ص� ��
			ListNode* removed;
			removed = p;
			p = removed->link;
			free(removed);
			head = p;
		}
		else {
			p = p->link;
		}
	}
	return head;
}

int len_list(ListNode* head) {
	int count = 0;
	for (ListNode* p = head; p != NULL; p = p->link)
		count++;
	return count;
}

int main(void) {
	ListNode* head = NULL;
	element num;
	int data[3];
	int len;
	
	printf("����� ���� : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("��� #%d�� ������ : ", i + 1);
		scanf_s("%d", &data[i]);
	}
	for (int i = 0; i < num; i++) {
		head = insert_first(head, data[i]);
	}
	len = len_list(head);
	printf("������ ���� �Է��Ͻÿ�: ");
	scanf_s("%d", &num);

	head = delete(head, num);
	printf("%d�� ���� ����Ʈ���� %d�� �����߽��ϴ�.", num, len - len_list(head));
	return 0;
}