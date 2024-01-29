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
	else (s->data[s->top++] = item);
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return (s->data[--s->top]);
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return (s->data[s->top]);
}

void run_length(char tmp[]) {
	int i, count = 0, check[26] = { 0, };
	int len = strlen(tmp);
	char n;
	StackType s, out;

	init_stack(&s);
	init_stack(&out);
	for (i = 0; i < len; i++) {
		n = tmp[i];
		if (n >= 'A' && n <= 'Z') {
			push(&s, n - 'A');
		}
		else if (n >= 'a' && n <= 'z') {
			push(&s, n - 'a');
		}
	}
	for (i = 0; i < len; i++) {
		n = peek(&s);
		if (n != peek(&s)) {
			check[n]++;
			push(&out, n);
			count++;
		}
		else {
			check[n]++;
			pop(&s);
		}
	}
	printf("압축된 문자열: ");
	for (i = 0; i < count; i++) {
		printf("%d%c", check[peek(&out)], (pop(&out) + 'a'));
	}
}

int main(void) {
	char tmp[100];
	printf("문자열을 입력하시오: ");
	scanf("%s", tmp);
	
	run_length(tmp);
	return 0;
}