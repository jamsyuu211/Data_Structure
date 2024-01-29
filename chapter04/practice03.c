#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stacktype;

void init_stack(Stacktype* s) {
	s->top = -1;
}

int is_empty(Stacktype* s) {
	return(s->top == -1);
}

int is_full(Stacktype* s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

void push(Stacktype* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스텍 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(Stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(Stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main() {
	Stacktype s;
	
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	return 0;
}