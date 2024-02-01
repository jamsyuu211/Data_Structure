#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
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

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element piv(QueueType* q, int n) {
	enqueue(q, 0);
	enqueue(q, 1);
	for (int i = 1; i < n; i++) {
		enqueue(q, dequeue(q) + q->data[q->rear]);
	}
	return q->data[q->rear];
}

int main(void) {
	QueueType q;
	init_queue(&q);
	for (int i = 2; i < 50; i++) {
		printf("%d\n", piv(&q, i));
		init_queue(&q);
	}
	return 0;
}