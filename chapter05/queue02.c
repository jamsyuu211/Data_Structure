//원형 큐

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { //큐 구조체
	element data[MAX_QUEUE_SIZE];
	int front, rear; //큐에는 후단과 전단이 있으므로 front, rear 2개를 선언함
}QueueType;

void error(char* message) { //에러 출력 함수
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) { //큐 초기화 함수
	q->front = q->rear = 0; //큐는 -1이 아닌 0부터 시작 why) -1부터 하면 포화상태가 되기때문?
}

int is_empty(QueueType* q) { //큐 공백상태 확인 함수
	return (q->front == q->rear); //원형큐에서는 큐의 후단과 전단이 같으면 공백임
}

int is_full(QueueType* q) { //큐 포화상태 확인 함수
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //원형큐에서j(rear + 1) % MAX_QUEUE_SIZE를 하면 큐사이즈에서 1작은 값까지 나머지가 추출된다.
}

void queue_print(QueueType* q) { //큐 출력 함수
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

void enqueue(QueueType* q, element item) {//원형큐의 삽입 함수
	if (is_full(q)) 
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //rear이 0이면 1, 1이면 2, 이런식으로 초기화됨
	q->data[q->rear] = item;//함수 실행시 +1만큼의 인덱스에 item 값이 들어감
}

element dequeue(QueueType* q) { //원형큐의 삭제 함수
	if (is_empty(q))
		error("큐가 공백입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //enqueue와 같음
	return q->data[q->front]; //전위 / 후위 연산자가 없는 이유는 바로 윗문장에서 그역할을 수행하기 때문이다
}

element peek(QueueType* q) {//원형큐에 먼저 들어온 front에 있는 값을 반환하는 peek 함수
	if (is_empty(q))
		error("큐가 공백입니다");
	return q->data[(q->front + 1) & MAX_QUEUE_SIZE]; 
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue)) {
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}

	printf("큐는 포화상태입니다.\n\n");
	
	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}