#include <cstdio>
#define MAX 1000
using namespace std;

// ����ü ����ä�
typedef struct Queue {
	int y, x;
	Queue(){}
	Queue(int y_, int x_) : y(y_), x(x_){}
};

int rear, front;

// ����ü Ÿ���� �迭 ����
Queue queue[MAX];

int main(void) {

	// ����ü ������ ����
	queue[rear].x = 10;
	queue[rear].y = 10; 
	//rear++; rear %= 1000;
	rear = ((rear += 1) % MAX);

	queue[rear].x = 5;
	queue[rear].y = 6; 
	//rear++; rear %= 1000;
	rear = ((rear += 1) % MAX);

	// �����ڸ� ����� ����
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