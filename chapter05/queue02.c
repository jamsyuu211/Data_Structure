//���� ť

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { //ť ����ü
	element data[MAX_QUEUE_SIZE];
	int front, rear; //ť���� �Ĵܰ� ������ �����Ƿ� front, rear 2���� ������
}QueueType;

void error(char* message) { //���� ��� �Լ�
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) { //ť �ʱ�ȭ �Լ�
	q->front = q->rear = 0; //ť�� -1�� �ƴ� 0���� ���� why) -1���� �ϸ� ��ȭ���°� �Ǳ⶧��?
}

int is_empty(QueueType* q) { //ť ������� Ȯ�� �Լ�
	return (q->front == q->rear); //����ť������ ť�� �Ĵܰ� ������ ������ ������
}

int is_full(QueueType* q) { //ť ��ȭ���� Ȯ�� �Լ�
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //����ť����j(rear + 1) % MAX_QUEUE_SIZE�� �ϸ� ť������� 1���� ������ �������� ����ȴ�.
}

void queue_print(QueueType* q) { //ť ��� �Լ�
	printf("QUEUE(front=%d rear =%d) = ", q->front, q->rear);
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

void enqueue(QueueType* q, element item) {//����ť�� ���� �Լ�
	if (is_full(q)) 
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //rear�� 0�̸� 1, 1�̸� 2, �̷������� �ʱ�ȭ��
	q->data[q->rear] = item;//�Լ� ����� +1��ŭ�� �ε����� item ���� ��
}

element dequeue(QueueType* q) { //����ť�� ���� �Լ�
	if (is_empty(q))
		error("ť�� �����Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //enqueue�� ����
	return q->data[q->front]; //���� / ���� �����ڰ� ���� ������ �ٷ� �����忡�� �׿����� �����ϱ� �����̴�
}

element peek(QueueType* q) {//����ť�� ���� ���� front�� �ִ� ���� ��ȯ�ϴ� peek �Լ�
	if (is_empty(q))
		error("ť�� �����Դϴ�");
	return q->data[(q->front + 1) & MAX_QUEUE_SIZE]; 
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue)) {
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}

	printf("ť�� ��ȭ�����Դϴ�.\n\n");
	
	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");
	return 0;
}