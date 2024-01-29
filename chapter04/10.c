#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element* data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType* s, int input) {
	s->top = -1;
	s->capacity = input;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
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

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return (s->data[s->top]);
}

int main(void) {
	int input, i;
	int* num;
	StackType s;
	printf("정수 배열의 크기: ");
	scanf_s("%d", &input);
	init_stack(&s, input);
	num = (int*)malloc(input * sizeof(int));

	printf("정수를 입력하시오: ");
	for (i = 0; i < input; i++) {
		scanf_s("%d", &num[i]);
		push(&s, num[i]);
	}
	
	printf("반전된 정수 배열: ");
	for (i = 0; i < input; i++) {
		printf("%d ", pop(&s));
	}
	
	free(num);
	free(&s);
	return 0;
}