//�ܼ� ���� ����Ʈ �ڵ� �������� �����ؼ� �ڵ� 2024-02-04
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct NodeType {
	element data;
	struct NodeType* link;
}NodeType;

int is_empty(NodeType* n) {
	return n == NULL; //*n == NULL�� �ƴ϶� n == NULL�� �ؾ� n�� index�� �񱳵ȴ�.
}

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(NodeType* n) {
	n->data = 0;
	n->link = NULL;
}
void insert_first(NodeType* n, element item) { //���ο� ��带 ��ȯ�ؾ���
	if (is_empty(n))
		error("��� ���� ����");
	NodeType* node = (NodeType*)malloc(sizeof(NodeType)); //��带 ��ȯ�ؾ� �ϰ�, ���ο� ��尡 ������ ��带 �����Ѿ� ��
	if (!(n->link == NULL))								  //���� �ߴ� ������ ������ ��带 �״�� �ΰ� ��� ������ �����Ű���� ��
		node->link = n->link;							  //åó�� ������ ¥�� �ξ� ����
	else
		node->link = NULL;
	node->data = item;
	n->link = node;
}

void insert(NodeType* n, element item, int pos) {
	if (is_empty(n))
		error("��� ���� ����");
	NodeType* node = (NodeType*)malloc(sizeof(NodeType));
	NodeType* prev = n;
	for (int i = 0; i < pos; i++) {
		prev = prev->link;
	}
	if (!(prev->link == NULL))
		node->link = prev->link;
	else
		node->link = NULL;
	node->data = item;
	prev->link = node;
}

element delete_first(NodeType* n) {
	if (is_empty(n))
		error("��� ���� ����");
	element item = n->link->data;
	if (!(n->link == NULL))
		n->link = n->link->link;
	free(n->link);
	return item;
}

element delete(NodeType* n, int pos) {
	if (is_empty(n))
		error("��� ���� ����");
	element item;
	NodeType* prev = n;
	for (int i = 0; i < pos; i++) {
		prev = prev->link;
	}
	item = prev->data;
	if (!(prev->link == NULL))
		prev = NULL;
	free(prev);
	return item;
}

int main(void) {
	NodeType head;
	init(&head);

	insert_first(&head, 1);
	insert_first(&head, 2);
	insert(&head, 3, 3);
	
	printf("%d\n", delete_first(&head));
	printf("%d\n", delete(&head, 1));

	return 0;
}