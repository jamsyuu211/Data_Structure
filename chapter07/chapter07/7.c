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

void insert(ListNode* before, element data) {
	ListNode* newcode = (ListNode*)malloc(sizeof(ListNode));
	newcode->data = data;
	newcode->llink = before;
	newcode->rlink = before->rlink;
	before->rlink->llink = newcode;
	before->rlink = newcode;
}

ListNode* search(ListNode* L, element data) {
	ListNode* p;
	p = L->rlink;
	
	do {
		if (p->data == data) {
			return p;
		}
		p = p->rlink;
	} while (p != L);
	fprintf(stderr, "검색오류\n");
	exit(1);
}

int main(void) {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	init(head);
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	
	printf("%d\n", search(head, 2)->data);
	printf("%d\n", search(head, 4)->data);
	return 0;
}