#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 20

int len = 0;
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
	return (q->rear == q->front);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //����� 1�� ����		
}

void add_front(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->data[q->front] = item; //������) ���� �ٲ�
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	len++;
}

void add_rear(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
	len++;
}

element delete_front(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element delete_rear(QueueType* q) {
	int prev = q->rear; //������
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_front(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[q->front];
}

element get_rear(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[q->rear];
}

int check(QueueType* q) {
	int i;
	if (len % 2 == 0 && len != 0) { //ť ���̰� ¦��
		for (i = 0; i < len / 2; i++) {
			if (delete_front(q) != delete_rear(q))
				return 0;
		}
		return 1;
	}
	else if (len % 2 == 1 && len != 0) {//ť ���̰� Ȧ��
		for (i = 0; i < len / 2; i++) {
			if (delete_front(q) != delete_rear(q))
				return 0;
		}
		return 1;
	}
	else if(len == 0)
		error("ť�� ��������Դϴ�");
}

int main(void) {
	QueueType q;

	init_queue(&q);
	add_front(&q, 'd');
	add_rear(&q, 'r');
	add_front(&q, 'r');
	add_rear(&q, 'a');
	add_front(&q, 'a');

	if (check(&q) == 1)
		printf("ȸ���Դϴ�\n");
	else
		printf("ȸ���� �ƴմϴ�\n");
	return 0;
}