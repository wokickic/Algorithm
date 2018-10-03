#include <iostream>
#include <vector>
#define GAMSI -1
#define RECOVER 1
#define WALL 6
using namespace std;

typedef struct CCTV {
	int y, x, ccNum;
	CCTV() {}
	CCTV(int y_, int x_, int ccNum_) : y(y_), x(x_), ccNum(ccNum_) {}
};

const int cam1[4][1][2] = { {{1, 0}}, 
							{{0,1}},
							{{-1,0}},
							{{0,-1}}};
const int cam2[2][2][2] = { {{1,0},{-1,0}},
							 {{0,1},{0,-1}}};
const int cam3[4][2][2] = { {{-1,0},{0,1}},
							{{0,1},{1,0}},
							{{1,0},{0,-1}},
							{{0,-1},{-1,0}}};
const int cam4[4][3][2] = { {{0,-1},{-1,0},{0,1}},
							{{-1,0},{0,1}, {1,0}},
							{{0,-1},{0,1},{1,0}},
							{{-1,0},{1,0},{0,-1}}};
const int cam5[1][4][2] = { { { 1, 0 },{ 0,1 },{ -1,0 },{ 0,-1 } } };

int n, m;
int ans = 987654321;
vector<vector<int>> map;
vector<CCTV> cctv;

void move(int y, int x, int ccnum, int i, int j, int sum) {
	if (ccnum == 1) {
		for (int  dir = 0; dir < j; dir++) {
			int ny = y;
			int nx = x;
			while (1) {
				ny = ny + cam1[i][dir][0];
				nx = nx + cam1[i][dir][1];
				// 범위 넘어가면 종료
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				// 벽만나면 종료
				if (map[ny][nx] == WALL) break;
				// 다른 cctv 만나면 넘어감
				if (map[ny][nx] >= 1 && map[ny][nx] <= 5) continue;

				map[ny][nx] += sum;
			}
		}
	}
	else if (ccnum == 2) {
		for (int dir = 0; dir < j; dir++) {
			int ny = y;
			int nx = x;
			while (1) {
				ny = ny + cam2[i][dir][0];
				nx = nx + cam2[i][dir][1];
				// 범위 넘어가면 종료
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				// 벽만나면 종료
				if (map[ny][nx] == WALL) break;
				// 다른 cctv 만나면 넘어감
				if (map[ny][nx] >= 1 && map[ny][nx] <= 5) continue;

				map[ny][nx] += sum;
			}
		}
	}
	else if (ccnum == 3) {
		for (int dir = 0; dir < j; dir++) {
			int ny = y;
			int nx = x;
			while (1) {
				ny = ny + cam3[i][dir][0];
				nx = nx + cam3[i][dir][1];
				// 범위 넘어가면 종료
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				// 벽만나면 종료
				if (map[ny][nx] == WALL) break;
				// 다른 cctv 만나면 넘어감
				if (map[ny][nx] >= 1 && map[ny][nx] <= 5) continue;

				map[ny][nx] += sum;
			}
		}
	}
	else if (ccnum == 4) {
		for (int dir = 0; dir < j; dir++) {
			int ny = y;
			int nx = x;
			while (1) {
				ny = ny + cam4[i][dir][0];
				nx = nx + cam4[i][dir][1];
				// 범위 넘어가면 종료
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				// 벽만나면 종료
				if (map[ny][nx] == WALL) break;
				// 다른 cctv 만나면 넘어감
				if (map[ny][nx] >= 1 && map[ny][nx] <= 5) continue;

				map[ny][nx] += sum;
			}
		}
	}
	else if (ccnum == 5) {
		for (int dir = 0; dir < j; dir++) {
			int ny = y;
			int nx = x;
			while (1) {
				ny = ny + cam5[i][dir][0];
				nx = nx + cam5[i][dir][1];
				// 범위 넘어가면 종료
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				// 벽만나면 종료
				if (map[ny][nx] == WALL) break;
				// 다른 cctv 만나면 넘어감
				if (map[ny][nx] >= 1 && map[ny][nx] <= 5) continue;

				map[ny][nx] += sum;
			}
		}
	}
}

void go(int idx) {
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				if (map[i][j] == 0) cnt += 1;
		ans = (ans > cnt ? cnt : ans);
		return;
	}
	int gamsiCnt, dir;
	int ccNum = cctv[idx].ccNum;

	if (ccNum == 1) { gamsiCnt = 4; dir = 1; }
	else if (ccNum == 2) { gamsiCnt = 2; dir = 2; }
	else if (ccNum == 3) { gamsiCnt = 4; dir = 2; }
	else if (ccNum == 4) { gamsiCnt = 4; dir = 3; }
	else { gamsiCnt = 1; dir = 4; }

	for (int j = 0; j < gamsiCnt; j++) {
		move(cctv[idx].y, cctv[idx].x, ccNum, j, dir, GAMSI);
		go(idx + 1);
		move(cctv[idx].y, cctv[idx].x, ccNum, j, dir, RECOVER);
	}
}

int main(void) {
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != WALL) cctv.push_back(CCTV(i, j, map[i][j]));
		}

	go(0);
	printf("%d\n", ans);
}