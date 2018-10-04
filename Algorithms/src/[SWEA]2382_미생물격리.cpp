#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;
int dy[] = { 0, -1, 1, 0, 0 };
int dx[] = { 0, 0, 0, -1, 1 };
int check[MAX][MAX][6];
queue<pair<int, int>> q;
int n, m, k;

struct microbe {
	int y, x, num, dir, id;
public:
	microbe() {}
	microbe(int y, int x, int n, int d, int i) : y(y), x(x), num(n), dir(d), id(i) {}
	void move() {
		y += dy[dir];
		x += dx[dir];
		if (x == 0 || y == 0 || x == (n - 1) || y == (n - 1)) {
			if (dir == 1) dir = 2;
			else if (dir == 2) dir = 1;
			else if (dir == 3) dir = 4;
			else if (dir == 4) dir = 3;
			num /= 2;
		}
	}
	void sum(int s) { num += s; }
	void clear() { num = 0; }
};

vector<microbe> v;
void find_MAX(int idx, int y, int x) {
	if (check[y][x][0] == -1) {
		check[y][x][0] = idx;
		q.push(make_pair(y, x));
	}
	// 가장큰 num값을 가진 구조체의 인덱스가 0번 배열에 저장됨
	else {
		int max = check[y][x][0];
		if (v[max].num < v[idx].num) {
			check[y][x][0] = idx;
			idx = max;
		}
		for (int i = 1; i < 6; i++) {
			if (check[y][x][i] == -1) { check[y][x][i] = idx; break; }
		}
	}
}
// 이동 방향 1 : 상, 2 : 하, 3 : 좌, 4 : 우
int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;
		// input
		for (int i = 0; i < k; i++) {
			int in1, in2, in3, in4;
			cin >> in1 >> in2 >> in3 >> in4;
			v.push_back(microbe(in1, in2, in3, in4, i));
		}
		// array init
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 6; k++) {
					check[i][j][k] = -1;
				}
			}
		}

		while (m--) {
			// move
			for (int i = 0; i < v.size(); i++) {
				if (v[i].num == 0) continue;
				v[i].move();
				find_MAX(i, v[i].x, v[i].y);
			}

			// merge
			while (!q.empty()) {
				int y = q.front().first;
				int x = q.front().second;
				int idx = check[y][x][0]; check[y][x][0] = -1;

				for (int i = 1; check[y][x][i] != -1; i++) {
					int k = check[y][x][i];
					v[idx].sum(v[k].num);
					v[k].clear(); check[y][x][i] = -1;
				}
				q.pop();
			}
		}
		int ans = 0;
		for (int i = 0; i < v.size(); i++) ans += v[i].num;
		
		printf("#%d %d\n", t, ans);
		v.clear();
	}
}