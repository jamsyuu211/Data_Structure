#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return q->front == q->rear;
}

int is_full(QueueType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void add_front(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void add_rear(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element delete_rear(QueueType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_front(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->front];
}

element get_rear(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

void a_steal(QueueType* q1, QueueType* q2) {
	if (is_empty(q1))
		add_rear(q1, delete_rear(q2));
	else if (is_empty(q2))
		add_rear(q2, delete_rear(q1));
}

int main(void) {
	QueueType deque1;
	QueueType deque2;

	init_queue(&deque1);
	init_queue(&deque2);

	// 덱에 요소 추가
	add_rear(&deque1, 1);
	add_rear(&deque1, 2);
	add_rear(&deque2, 3);
	add_rear(&deque2, 4);

	// A-Steal 알고리즘 실행
	a_steal(&deque1, &deque2);

	// 결과 출력
	printf("deque1: ");
	while (!is_empty(&deque1)) {
		printf("%d ", delete_front(&deque1));
	}
	printf("\ndeque2: ");
	while (!is_empty(&deque2)) {
		printf("%d ", delete_front(&deque2));
	}
	printf("\n");
	return 0;
}