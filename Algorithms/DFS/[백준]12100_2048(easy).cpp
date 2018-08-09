#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int n, ans;

// 게임판 움직여서 값 더하기
vector<vector<int>> move(int dir, vector<vector<int>>& map) {
	vector<vector<int>> retmap = map;

	if (dir == 0) { // 오른쪽으로 기울임
		for (int y = 0; y < n; y++) {
			// 1. 더하기
			int sum = 0; int by, bx;
			for (int x = n - 1; x >= 0; x--) {
				if (retmap[y][x] == 0) continue;
				if (sum == 0) { 
					sum = retmap[y][x]; 
					by = y; bx = x;
				}
				else {
					if (sum == retmap[y][x]) {
						retmap[by][bx] = sum * 2;
						retmap[y][x] = 0;
						sum = 0;
					}
					else { sum = retmap[y][x]; by = y; bx = x; }
				}
			}
			// 2. 오른쪽 벽으로 밀기
			queue<pair<int, int>>q;
			for (int x = n - 1; x >= 0; x--) {
				if (retmap[y][x] == 0) { q.push(make_pair(y, x)); continue; }
				if (retmap[y][x] != 0 && !q.empty()) {
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop();
					retmap[ny][nx] = retmap[y][x];
					retmap[y][x] = 0; q.push(make_pair(y, x));
				}
			}
		}
	}
	else if (dir == 1) { // 아래로 기울임
		for (int x = 0; x < n; x++) {
			// 1. 더하기
			int sum = 0; int by, bx;
			for (int y = n - 1; y >= 0; y--) {
				if (retmap[y][x] == 0) continue;
				if (sum == 0) {
					sum = retmap[y][x];
					by = y; bx = x;
				}
				else {
					if (sum == retmap[y][x]) {
						retmap[by][bx] = sum * 2;
						retmap[y][x] = 0;
						sum = 0;
					}
					else { sum = retmap[y][x]; by = y; bx = x; }
				}
			}
			// 2. 아래쪽 벽으로 밀기
			queue<pair<int, int>>q;
			for (int y = n - 1; y >= 0; y--) {
				if (retmap[y][x] == 0) { q.push(make_pair(y, x)); continue; }
				if (retmap[y][x] != 0 && !q.empty()) {
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop();
					retmap[ny][nx] = retmap[y][x];
					retmap[y][x] = 0; q.push(make_pair(y, x));
				}
			}
		}
	}
	else if (dir == 2) { // 왼쪽으로 기울임
		for (int y = 0; y < n; y++) {
			// 1. 더하기
			int sum = 0; int by, bx;
			for (int x = 0; x < n; x++) {
				if (retmap[y][x] == 0) continue;
				if (sum == 0) {
					sum = retmap[y][x];
					by = y; bx = x;
				}
				else {
					if (sum == retmap[y][x]) {
						retmap[by][bx] = sum * 2;
						retmap[y][x] = 0;
						sum = 0;
					}
					else { sum = retmap[y][x]; by = y; bx = x; }
				}
			}
			// 2. 아래쪽 벽으로 밀기
			queue<pair<int, int>>q;
			for (int x = 0; x < n; x++) {
				if (retmap[y][x] == 0) { q.push(make_pair(y, x)); continue; }
				if (retmap[y][x] != 0 && !q.empty()) {
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop();
					retmap[ny][nx] = retmap[y][x];
					retmap[y][x] = 0; q.push(make_pair(y, x));
				}
			}
		}
	}
	else { // 위로 기울임
		for (int x = 0; x < n; x++) {
			// 1. 더하기
			int sum = 0; int by, bx;
			for (int y = 0; y < n; y++) {
				if (retmap[y][x] == 0) continue;
				if (sum == 0) {
					sum = retmap[y][x];
					by = y; bx = x;
				}
				else {
					if (sum == retmap[y][x]) {
						retmap[by][bx] = sum * 2;
						retmap[y][x] = 0;
						sum = 0;
					}
					else { sum = retmap[y][x]; by = y; bx = x; }
				}
			}
			// 2. 아래쪽 벽으로 밀기
			queue<pair<int, int>>q;
			for (int y = 0; y < n; y++) {
				if (retmap[y][x] == 0) { q.push(make_pair(y, x)); continue; }
				if (retmap[y][x] != 0 && !q.empty()) {
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop();
					retmap[ny][nx] = retmap[y][x];
					retmap[y][x] = 0; q.push(make_pair(y, x));
				}
			}
		}
	}
	return retmap;
}

void dfs(int dir, int cnt, vector<vector<int>> map) {
	if (cnt == 5) {
		// 최대 값 구하기
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!map[i][j]) continue;
				ans = max(ans, map[i][j]);
			}
		return;
	}
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> copymap = move(i, map);
		dfs(i, cnt + 1, copymap);
	}
}

int main(void) {
	cin >> n; ans = 0;
	vector<vector<int>> map (n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	
	dfs(0, 0, map);
	printf("%d\n", ans);
} 