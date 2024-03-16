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
	for (ListNode* p = head; p != NULL;) { //증감식이 있으면 밑에 if문이 수행됐을때 한번더 증가되기 때문에 else문으로 추가함
		if (p->data == value) {//p가 어차피 증가하므로 head값만 생각해도 됨
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
	
	printf("노드의 개수 : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("노드 #%d의 데이터 : ", i + 1);
		scanf_s("%d", &data[i]);
	}
	for (int i = 0; i < num; i++) {
		head = insert_first(head, data[i]);
	}
	len = len_list(head);
	printf("삭제할 값을 입력하시오: ");
	scanf_s("%d", &num);

	head = delete(head, num);
	printf("%d를 연결 리스트에서 %d번 삭제했습니다.", num, len - len_list(head));
	return 0;
}