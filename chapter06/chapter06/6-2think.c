//단순 연결 리스트 코드 보기전에 생각해서 코딩 2024-02-04
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct NodeType {
	element data;
	struct NodeType* link;
}NodeType;

int is_empty(NodeType* n) {
	return n == NULL; //*n == NULL이 아니라 n == NULL을 해야 n의 index가 비교된다.
}

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(NodeType* n) {
	n->data = 0;
	n->link = NULL;
}
void insert_first(NodeType* n, element item) { //새로운 헤드를 반환해야함
	if (is_empty(n))
		error("노드 공백 오류");
	NodeType* node = (NodeType*)malloc(sizeof(NodeType)); //헤드를 반환해야 하고, 새로운 노드가 기존의 헤드를 가리켜야 함
	if (!(n->link == NULL))								  //내가 했던 생각은 기존의 헤드를 그대로 두고 헤드 다음에 연결시키려고 함
		node->link = n->link;							  //책처럼 구조를 짜면 훨씬 편함
	else
		node->link = NULL;
	node->data = item;
	n->link = node;
}

void insert(NodeType* n, element item, int pos) {
	if (is_empty(n))
		error("노드 공백 오류");
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
		error("노드 공백 오류");
	element item = n->link->data;
	if (!(n->link == NULL))
		n->link = n->link->link;
	free(n->link);
	return item;
}

element delete(NodeType* n, int pos) {
	if (is_empty(n))
		error("노드 공백 오류");
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