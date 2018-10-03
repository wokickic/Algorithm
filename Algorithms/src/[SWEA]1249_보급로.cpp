#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

vector<vector<int>> map;
int n;
typedef struct Point {
	int t;
	int y, x;
	
	Point() {}
	Point(int y_, int x_, int t_) : y(y_), x(x_), t(t_) {}
};

// 우선순위큐에서 구조체의 우선순위를 비교하기 위한 구조체
typedef struct cmp {
	bool operator()(Point a, Point b) { return a.t > b.t; }
};

// 복구시간이 모두 다르기 때문에 다익스트라 적용해봄
int dijkstra() {
	// 모든 영역을 아직 방문 안했다고 가정함. INF로 visit벡터 초기화
	vector<vector<int>> visit(n, vector<int>(n, INF));

	// 우선순위큐 사용, Point라는 구조체를 힙정렬해줘야 하기 때문에 
	// cmp라는 비교함수 사용
	priority_queue<Point, vector<Point>, cmp> pq;
	visit[0][0] = 0;
	pq.push(Point(0, 0, 0));

	while (!pq.empty()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int t = pq.top().t;
		pq.pop();
		// visit에 현재 꺼낸 값보다 작은 값이 있으면 다음 반복 수행
		if (visit[y][x] < t) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				int nt = t + map[ny][nx];
				// visit의 값이 더크면 visit에 더작은 값을 넣고 큐에 삽입
				if (visit[ny][nx] > nt) {
					visit[ny][nx] = nt;
					pq.push(Point(ny, nx, nt));
				}
			}
		}
	}
	// while()문이 끝나면 도착지점의 visit에는 최소시간이 저장되어있음
	return visit[n - 1][n - 1];
}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n;
		map = vector<vector<int>>(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%1d", &map[i][j]);
		
		printf("#%d %d\n", t, dijkstra());
	}
}