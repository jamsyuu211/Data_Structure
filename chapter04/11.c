#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스텍 포화 에러\n");
		return;
	}
	else (s->data[++s->top] = item);
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return (s->data[s->top--]);
}

void check_matching(char tmp[]) {
	int i, left = 0;
	char n;
	int len = strlen(tmp);
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		n = tmp[i];
		switch (n) {
		case '(':
			push(&s, ++left);
			printf("%d ", left);
			break;
		case ')':
			printf("%d ", pop(&s));
			break;
		}
	}
}

int main(void) {
	char tmp[100];
	printf("수식: ");
	scanf("%s", tmp);

	printf("괄호수: ");
	check_matching(tmp);
	return 0;
}