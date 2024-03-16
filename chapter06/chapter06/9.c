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

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main(void) {
	ListNode* p = NULL;
	element num;
	printf("노드의 개수 : ");
	scanf_s("%d", &num);
	int* count = (int*)malloc(num * sizeof(int));

	for (int i = 0; i < num; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &count[i]);
	}
	for (int i = 0; i < num; i++) {
		p = insert_first(p, count[num - 1 - i]);
	}
	print_list(p);
	free(count);
	return 0;
}
