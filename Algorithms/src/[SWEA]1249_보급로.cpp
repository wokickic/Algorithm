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

// �켱����ť���� ����ü�� �켱������ ���ϱ� ���� ����ü
typedef struct cmp {
	bool operator()(Point a, Point b) { return a.t > b.t; }
};

// �����ð��� ��� �ٸ��� ������ ���ͽ�Ʈ�� �����غ�
int dijkstra() {
	// ��� ������ ���� �湮 ���ߴٰ� ������. INF�� visit���� �ʱ�ȭ
	vector<vector<int>> visit(n, vector<int>(n, INF));

	// �켱����ť ���, Point��� ����ü�� ����������� �ϱ� ������ 
	// cmp��� ���Լ� ���
	priority_queue<Point, vector<Point>, cmp> pq;
	visit[0][0] = 0;
	pq.push(Point(0, 0, 0));

	while (!pq.empty()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int t = pq.top().t;
		pq.pop();
		// visit�� ���� ���� ������ ���� ���� ������ ���� �ݺ� ����
		if (visit[y][x] < t) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				int nt = t + map[ny][nx];
				// visit�� ���� ��ũ�� visit�� ������ ���� �ְ� ť�� ����
				if (visit[ny][nx] > nt) {
					visit[ny][nx] = nt;
					pq.push(Point(ny, nx, nt));
				}
			}
		}
	}
	// while()���� ������ ���������� visit���� �ּҽð��� ����Ǿ�����
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