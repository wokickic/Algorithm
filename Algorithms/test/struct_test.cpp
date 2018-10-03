#include <cstdio>
#define MAX 1000
using namespace std;

// 구조체 선어ㅓㄴ
typedef struct Queue {
	int y, x;
	Queue(){}
	Queue(int y_, int x_) : y(y_), x(x_){}
};

int rear, front;

// 구조체 타입의 배열 선언
Queue queue[MAX];

int main(void) {

	// 구조체 변수에 접근
	queue[rear].x = 10;
	queue[rear].y = 10; 
	//rear++; rear %= 1000;
	rear = ((rear += 1) % MAX);

	queue[rear].x = 5;
	queue[rear].y = 6; 
	//rear++; rear %= 1000;
	rear = ((rear += 1) % MAX);

	// 생성자를 사용한 삽입
	queue[rear] = Queue(56, 77);
	rear = ((rear += 1) % MAX);

	queue[rear] = Queue(81, 97);
	rear = ((rear += 1) % MAX);

	printf("(x, y) = (%d, %d)\n", queue[front].x, queue[front].y); 
	//front++; front %= 1000;
	front = ((front += 1) % MAX);
	
	printf("(x, y) = (%d, %d)\n", queue[front].x, queue[front].y);
	//front++; front %= 1000;
	front = ((front += 1) % MAX);

	printf("(x, y) = (%d, %d)\n", queue[front].x, queue[front].y);
	//front++; front %= 1000;
	front = ((front += 1) % MAX);

	printf("(x, y) = (%d, %d)\n", queue[front].x, queue[front].y);
	//front++; front %= 1000;
	front = ((front += 1) % MAX);
}