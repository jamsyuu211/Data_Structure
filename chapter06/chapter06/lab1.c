#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* list = (ListNode*)malloc(sizeof(ListNode));
	list->link = head;
	list->data = value;
	head = list;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* list = head; list != NULL; list = list->link) {
		printf("%s->", list->data.name);
	}
	printf("NULL \n");
}

int main(void) {
	ListNode* head = NULL;
	element data;
	
	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);
	return 0;
}