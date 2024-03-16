#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[100];
	int age;
	double heigh;
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

int main(void) {
	ListNode* head = NULL;
	int num = 4;
	element data[4];
	
	for (int i = 0; i < num; i++) {
		printf("name : ");
		scanf("%s", data[i].name);
		printf("age : ");
		scanf("%d", &data[i].age);
		printf("heigh : ");
		scanf("%lf", &data[i].heigh);
		printf("\n");
	}

	for (int i = 0; i < num; i++) {
		head = insert_first(head, data[i]);
	}
	for (int i = 0; i < num; i++) {
		printf("%s / %d / %.1lf\n", data[i].name, data[i].age, data[i].heigh);
	}
	return 0;
}