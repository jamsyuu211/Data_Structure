#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(DequeType* q) { //초기화
	q->front = q->rear = 0;
}

int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(DequeType* q, element item) {//전단 삽입 함수 enqueue랑 같음
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType* q) { //후단 삭제함수 dequeue랑 같음
	if (is_empty(q)) {
		error("큐가 공백상태입니다");
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

element get_front(DequeType* q) { //후단 반환 함수
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + MAX_QUEUE_SIZE)];
}

void add_front(DequeType* q, element val) {//후단 삽입 함수
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q) {//전단 삭제 함수
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev]; //기존 q->rear 인덱스의 값을 반환함
}

element get_rear(DequeType* q) {//전단 반환 함수
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

int main(void) {
	DequeType queue;

	init_deque(&queue);
	for (int i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}