#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n");
	exit(1);
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
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

int get_count(QueueType* q) {
	if (is_full(q))
		return MAX_QUEUE_SIZE - 1;
	else if ((q->rear + 1) % MAX_QUEUE_SIZE < (q->front + 1) % MAX_QUEUE_SIZE)
		return q->rear - q->front;
	else if ((q->rear + 1) % MAX_QUEUE_SIZE > (q->front + 1) % MAX_QUEUE_SIZE)
		return ((q->rear + 1) % MAX_QUEUE_SIZE - (q->front + 1) % MAX_QUEUE_SIZE);
	else if (is_empty(q))
		return 0;
}

int main(void) {
	QueueType q;
	
	init_queue(&q);
	printf("%d\n", get_count(&q));
	for (int i = 0; i < 5; i++) {
		enqueue(&q, i);
		printf("%d\n", get_count(&q));
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		dequeue(&q);
		printf("%d\n", get_count(&q));
	}
	return 0;
}