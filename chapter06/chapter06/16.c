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
	for (; p->link != NULL; p = p->link) { //마지막 노드가  NULL이 아니라 마지막 노드의 link가 NULL이면 종료이므로 p->link != NULL이 되어야 함
			ListNode* removed; //노드 갯수가 홀수인 경우엔 마지막 노드의 링크가 NULL이라 괜찮지만 노드 갯수가 짝수면 오류가 발생함
			removed = p->link;
			if (removed->link == NULL) {//노두 갯수가 짝수일 경우 예외처리
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