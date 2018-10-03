// 비주얼스튜디오 스택영역 사이즈 조정하기
// http://copynull.tistory.com/40

#include <cstdio>
// 1000으로하니까 스택 터짐
#define MAX 100
using namespace std;

typedef struct Point {
	int y, x;
public:
	Point() {}
	Point(int y_, int x_) : y(y_), x(x_) {}
};

template <typename T>
class myQueue {
	int ffront, rear;
	int queue_size;
	T arr[MAX];

public:
	myQueue() { queue_size = ffront = rear = 0; }

	void push_back(T tmp) {
		arr[rear] = tmp;
		rear = ((rear += 1) % MAX);
		queue_size++;
	}
	void pop() { ffront = ((ffront += 1) % MAX); queue_size--; }

	T front() { return arr[ffront]; }

	bool empty() { 
		if (rear == ffront) return true;
		return false;
	}

	int size() { return queue_size; }
};

template <typename T>
class myStack {
	int peak, stack_size;
	T arr[MAX];

public:
	myStack() { peak = -1; stack_size = 0; }

	T top() { return arr[peak]; }
	void push(T tmp) { arr[++peak] = tmp; stack_size++; }
	void pop() { peak--; stack_size--; }
	int size() { return stack_size; }
	int empty() {
		if (peak == -1) return true;
		return false;
	}
};

int main(void) {
	myQueue<Point> q, q1;

	printf("***** q test *****\n");
	printf("empty :  %d\n", q.empty());
	q.push_back({ 1, 2 });
	q.push_back({ 3, 4 });

	printf("size : %d\n", q.size());

	while (!q.empty()) {
		printf("(y, x) = (%d, %d)\n", q.front().y, q.front().x);
		q.pop(); 
	}
	printf("size : %d\n", q.size());

	printf("***** qq test *****\n");
	myQueue<myQueue<Point>> qq;
	printf("qq size : %d\n", qq.size());
	
	q.push_back({ 1, 2 }); q.push_back({ 3, 4 }); q.push_back({ 6, 7 });
	q1.push_back({ 10, 11 }); q1.push_back({ 12, 13 }); q1.push_back({ 14, 15 });
	qq.push_back(q); qq.push_back(q1);
	
	printf("qq size : %d\n", qq.size());
	while (!qq.empty()){
		myQueue<Point> temp_q = qq.front();
		qq.pop();
		while (!temp_q.empty()) {
			printf("(y, x) = (%d, %d)\n", temp_q.front().y, temp_q.front().x);
			temp_q.pop();
		}
	}

	printf("***** stack test *****\n");
	
	myStack<Point> s;
	s.push({ 5, 6 });
	s.push(Point(7, 7));
	printf("size : %d\n", s.size());
	printf("top : (%d, %d)\n", s.top().y, s.top().x);
	s.push(Point(8, 9));


	while (!s.empty()){
		printf("top : (%d, %d)\n", s.top().y, s.top().x);
		s.pop();
	}
	printf("size : %d\n", s.size());
}