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

element peek(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void) {
	int minutes = 60; //시간이 60이 되면 종료
	int total_wait = 0; //clock - customer.arrival_time을 누계로 계산함
	int total_customers = 0; //새로운 고객이 들어오면 (rand() % 10) < 3 -> +1을 누계함
	int service_time = 0; //현재처리중인 고객의 서비스 시간 0이면 서비스 안받고 있음 아니면 받는 중 //시간(clock)이 지나면 하나 감소함
	int service_customer; //customer.id
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) { //clock = 현재시각
		printf("현재시각=%d\n", clock);
		if ((rand() % 10) < 3) { //이 조건을 만족하면 새로운 고객이 들어온 것임
			element customer;
			customer.id = total_customers++; //0,1,2 이런식으로 id가 정해짐
			customer.arrival_time = clock; //도착시간을 현재시각으로
			customer.service_time = rand() % 3 + 1; //서비스 받는시간을 1~3으로 설정
			enqueue(&queue, customer);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) { //이 조건을 만족시키면 업무를 처리중인 상황임
			printf("고객 %d 업무처리중입니다. \n", service_customer);
			service_time--; //이 문장이 수행되면 service_time은 0이 되므로 서비스를 처리하는 중이 아님
		}
		else {
			if (!is_empty(&queue)) {//service_time이 0이면
				element customer = dequeue(&queue); //대기중인 고객을 서비스를 받도록 dequeue함
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("고객 % d이 % d분에 업무를 시작합니다.대기시간은 % d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time; //총 기다린 시간 계산
			}
		}
	}
	printf("전체 대기 시간=%d분 \n", total_wait);
	return 0;
}