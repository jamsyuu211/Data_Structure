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

int search_list(ListNode* head, element value) {
	int count = 0;
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (value == p->data)
			count++;
	}
	return count;
}

int main(void) {
	ListNode* head = NULL;
	int num;
	int search;
	printf("노드의 개수 : ");
	scanf_s("%d", &num);

	int* value = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &value[i]);
	}
	for (int i = 0; i < num; i++) {
		head = insert_first(head, value[num - 1 - i]);
	}
	printf("탐색할 값을 입력하시오 : ");
	scanf_s("%d", &search);
	printf("%d는 연결리스트에서 %d번 나타납니다.", search, search_list(head, search));
	return 0;
}