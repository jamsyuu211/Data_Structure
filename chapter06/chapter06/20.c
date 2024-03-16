#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int first; //계수
	int second; //차수
}element;

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

ListNode* add_func(ListNode* a, ListNode* b) {
	ListNode* head = NULL;
	while(a != NULL && b != NULL){
			if (a->data.second == b->data.second) {
				element value;
				value.first = a->data.first + b->data.first;
				value.second = a->data.second + b->data.second;
				head = insert_first(head, value);
			}
			else {
				if (a->data.second < b->data.second) {
					head = insert_first(head, a->data);
					a = a->link;
				}
				else {
					head = insert_first(head, b->data);
					b = b->link;
				}
			}
	}
	if (a != NULL) {
		while (a != NULL) {
			head = insert_first(head, a->data);
			a = a->link;
		}
	}
	else if (b != NULL) {
		while (b != NULL) {
			head = insert_first(head, b->data);
			b = b->link;
		}
	}
	return head;
}

void print(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%dX^%d + ", p->data.first, p->data.second);
	}
	printf("NULL \n");
}

int main(void) {
	ListNode* a = NULL;
	ListNode* b = NULL;
	element A[4] = { (3,6), (7,3), (-2,2), (-9, 0) };
	element B[5] = { (-2, 6), (-4,4), (6,2), (6,1), (1,0) };
	
	for (int i = 0; i < 4; i++) {
		a = insert_first(a, A[i]);
	}
	for (int i = 0; i < 5; i++) {
		b = insert_first(b, B[i]);
	}

	print(add_func(a, b));
	return 0;
}