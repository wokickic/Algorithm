#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int n, l, r, ans;

typedef struct Point {
	int y;
	int x;
	Point() { y = 0, x = 0; }
	Point(int _y, int _x) : y(_y), x(_x) {}
};
vector<vector<int>> map, check;
queue<Point> q;

bool bfs(int y, int x, int lv) {
	q.push(Point(y, x));
	int ret = 0;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		//check[y][x] = lv;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				if (check[ny][nx] == 0) {
					int diff = map[y][x] - map[ny][nx];
					diff = (diff < 0 ? diff * (-1) : diff);
					if (diff < l || diff > r) continue;
					q.push(Point(ny, nx));
					check[ny][nx] = lv;
					if (!ret) ret = 1;
					else check[y][x] = lv;
				}
			}
		}
	}
	return ret;
}


int main(void) {
	cin >> n >> l >> r;
	check = map = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	while (1) {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0) ret += bfs(i, j, ret + 1);
			}
		}

		if (!ret) break;

		ans += 1;
		
		//1차원 배열에 값을 저장
		vector<Point> mem = vector<Point>(ret + 2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int idx = check[i][j];
				if (idx == 0) continue;
				// y = 누적값, x = 몇번 더했는지
				mem[idx].y = mem[idx].y + map[i][j];
				mem[idx].x += 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0) continue;
				map[i][j] = mem[check[i][j]].y / mem[check[i][j]].x;
			}
		}

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) check[i][j] = 0;
	}

	printf("%d\n", ans);
}