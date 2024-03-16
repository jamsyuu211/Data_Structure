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
	for (ListNode* p = head; p != NULL; p = p->link) //p = head인 이유 insert_first()를 5, 6, 7 로 실행시키면 head의 data는 5이기 때문
		sum += p->data;
	return sum;
}

int main(void) {
	int num;
	ListNode* head = NULL;
	
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

	printf("연결 리스트의 데이터 합: %d", sum_list(head));
	return 0;
}