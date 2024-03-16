#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef; //계수
	int expon; //차수
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int size; //리스트 크기
	ListNode* head;//리스트 헤드
	ListNode* tail;//리스트 끝
}ListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");//예외 처리

	//초기화
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	//연결
	if (plist->tail == NULL) { //맨 뒷값이 없으면
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp; //맨뒤에 추가
		plist->tail = temp;
	}
	plist->size++; //추가했으니까 size + 1
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {//a, b둘 모두 1이면 == a,b둘중 하나라도 NULL이 아니면
		if (a->expon == b->expon) { //차수가 같으면
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) { //a차수가 더 크면
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {//b차수가 더 크면
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}


	//위에 while문에서 a or b둘중 하나는 NULL이 돼야 끝나므로 밑에 2개 for문에서는 NULL로 바뀐 a or b for문은 실행되지 않음
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%d^%d + ", p->coef, p->expon);
	}
	printf("\n");
}

int main(void) {
	ListType* list1, * list2, * list3;
	
	list1 = create();
	list2 = create();	
	list3 = create();

	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1); free(list2); free(list3);
}