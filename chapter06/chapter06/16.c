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

ListNode* delete_list(ListNode* head) {
	ListNode* p = head;
	ListNode* result = p;
	for (; p->link != NULL; p = p->link) { //������ ��尡  NULL�� �ƴ϶� ������ ����� link�� NULL�̸� �����̹Ƿ� p->link != NULL�� �Ǿ�� ��
			ListNode* removed; //��� ������ Ȧ���� ��쿣 ������ ����� ��ũ�� NULL�̶� �������� ��� ������ ¦���� ������ �߻���
			removed = p->link;
			if (removed->link == NULL) {//��� ������ ¦���� ��� ����ó��
				free(removed);
				p->link = NULL;
				return result;
			}
			p->link = removed->link;
			free(removed);
	}
	return result;
}

void print(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

int main(void) {
	ListNode* head = NULL;

	for (int i = 0; i < 10; i++) {
		head = insert_first(head, i);
	}
	print(head);

	print(delete_list(head));
	return 0;
}