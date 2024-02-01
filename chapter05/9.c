#include <stdio.h>
#include <stdlib.h>
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
	else s->data[++s->top] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top--];
}

void in(int n, StackType *s1) {
	push(s1, n);
}

element out(StackType* s1, StackType* s2) {
	if (is_empty(s2)) {
		while (!is_empty(s1)) {
			push(s2, pop(s1));
		}
	}
	return pop(s2);
}

int main(void) {
	StackType s1, s2;
	
	init_stack(&s1);
	init_stack(&s2);

	int i;
	for (i = 0; i < 5; i++) {
		in(i, &s1);
	}
	//out(&s1, &s2);
	for (i = 0; i < 5; i++) {
		printf("%d\n", out(&s1, &s2));
	}
	return 0;
}