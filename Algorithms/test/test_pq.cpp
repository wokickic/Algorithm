#include <iostream>
#include <queue>
using namespace std;

typedef struct Point {
	int t;
	int y;
	int x;

	Point() {}
	Point(int y_, int x_, int t_) : y(y_), x(x_), t(t_) {}
};

//bool cmp(Point a, Point b) {
//	return a.t > b.t;
//}
typedef struct cmp{
	bool operator()(Point a, Point b) {
		return a.t > b.t;
	}
};

int main(void) {
	priority_queue<Point, vector<Point>, cmp> pq;

	pq.push(Point(0, 0, 4));
	pq.push(Point(1, 3, 3));
	pq.push(Point(2, 1, 5));
	pq.push(Point(2, 0, 1));
	pq.push(Point(2, 0, 6));

	pq.pop();
	pq.pop();
	pq.pop();
	pq.pop();


	printf(" ");
}