#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_QUEUE_SIZE 10


typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;

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
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void) {
	int minutes = 60; //�ð��� 60�� �Ǹ� ����
	int total_wait = 0; //clock - customer.arrival_time�� ����� �����
	int total_customers = 0; //���ο� ���� ������ (rand() % 10) < 3 -> +1�� ������
	int service_time = 0; //����ó������ ���� ���� �ð� 0�̸� ���� �ȹް� ���� �ƴϸ� �޴� �� //�ð�(clock)�� ������ �ϳ� ������
	int service_customer; //customer.id
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) { //clock = ����ð�
		printf("����ð�=%d\n", clock);
		if ((rand() % 10) < 3) { //�� ������ �����ϸ� ���ο� ���� ���� ����
			element customer;
			customer.id = total_customers++; //0,1,2 �̷������� id�� ������
			customer.arrival_time = clock; //�����ð��� ����ð�����
			customer.service_time = rand() % 3 + 1; //���� �޴½ð��� 1~3���� ����
			enqueue(&queue, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) { //�� ������ ������Ű�� ������ ó������ ��Ȳ��
			printf("�� %d ����ó�����Դϴ�. \n", service_customer);
			service_time--; //�� ������ ����Ǹ� service_time�� 0�� �ǹǷ� ���񽺸� ó���ϴ� ���� �ƴ�
		}
		else {
			if (!is_empty(&queue)) {//service_time�� 0�̸�
				element customer = dequeue(&queue); //������� ���� ���񽺸� �޵��� dequeue��
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("�� % d�� % d�п� ������ �����մϴ�.���ð��� % d���̾����ϴ�.\n", customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time; //�� ��ٸ� �ð� ���
			}
		}
	}
	printf("��ü ��� �ð�=%d�� \n", total_wait);
	return 0;
}