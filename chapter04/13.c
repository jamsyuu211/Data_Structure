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
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스텍 포화 에러\n");
		return;
	}
	else (s->data[++(s->top)] = item);
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return (s->data[(s->top)--]);
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return (s->data[s->top]);
}

void check_num(char tmp[]) {
	int i, count = 0;
	int len = strlen(tmp);
	char n, num[10] = { 0, };
	StackType s, out;

	init_stack(&s);	  //기본 스텍
	init_stack(&out); //정방향으로 출력하기위한 스텍
	for (i = 0; i < len; i++) {
		n = tmp[i];
		if (num[n - '0'] == 0) { //n이 문자열이라 숫자로 index값을 맞추기위해 n - '0'을 사용함
			push(&s, (n - '0'));
			num[n - '0']++;
			count++; //out스텍에 pop 공백에러가 발생하지 않도록 count 변수를 누계함
		}
	}
	for (i = 0; i < count; i++) {
		push(&out, pop(&s));
	}
	while (!is_empty(&out)) {
		printf("%d", pop(&out));
	}
}

int main(void) {
	char input[100];
	printf("정수를 입력하시오: ");
	scanf(" %s", input);
	
	printf("출력: ");
	check_num(input);
	return 0;
}
