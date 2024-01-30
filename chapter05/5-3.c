#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void init_queue(QueueType* q) {
	q->front = 0; //q->front = q->rear = 0;
	q->rear = 0;
}

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear) //이해안됨 front 바로앞에 rear이 있어서? why?
				break;
		} while (i != q->front); //0 - 1 / 1 - 2 /이런식인데 이해안됨
	}
	printf("\n");
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //rear 하나 증가시키고 MAX_QUEUE_SIZE - 1만큼의 나머지로 초기화됨
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //rear -> front로 변경하면 위와 동일
	return q->data[q->front];
}

element peek(QueueType * q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);
	srand(time(NULL));
	
	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) {
			enqueue(&queue, rand() % 100);
		}
		queue_print(&queue);
		if (rand() % 10 == 0) {
			int data = dequeue(&queue);
		}
		queue_print(&queue);
	}
	return 0;
}