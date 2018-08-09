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

	if (dir == 0) { // 오른쪽으로 이동시킬때
		for (int y = 0; y < n; y++) {
			// 1. 더하기
			// 더하는 순서는 오른쪽에서 왼쪽으로 이동하면서
			// 이전의 값과 일치하면 더해주고 그렇지 않으면 이전의값을 
			// 현재값으로 바꿔줌
			int sum = 0; int by, bx;
			// 오른쪽에서 왼쪽으로 이동
			for (int x = n - 1; x >= 0; x--) {
				if (retmap[y][x] == 0) continue;
				if (sum == 0) { 
					sum = retmap[y][x]; 
					// 다음 값이랑 더해서 저장하기위해 지금위치 저장
					by = y; bx = x;
				}
				else {
					// 이전에 값과 현재위치의 값이 같으면
					if (sum == retmap[y][x]) {
						// 2배해서 저장하고
						retmap[by][bx] = sum * 2;
						// 현재위치는 0으로 해주고 sum도 다시 0으로 초기화
						retmap[y][x] = 0;
						sum = 0;
					}
					// 이전의 값과 현재 위치의 값이 다르면
					// 현재 값을 sum으로 해줌
					else { sum = retmap[y][x]; by = y; bx = x; }
				}
			}
			// 2. 오른쪽 벽으로 밀기
			// 큐에는 빈칸인 좌표를 저장
			queue<pair<int, int>>q;
			// 오른쪽에서 왼족으로 탐색
			for (int x = n - 1; x >= 0; x--) {
				// 빈칸의 좌표 큐에 저장
				if (retmap[y][x] == 0) { q.push(make_pair(y, x)); continue; }
				if (retmap[y][x] != 0 && !q.empty()) {
					// 빈칸이 아니고 큐가 안비어 있으면
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop();
					// 현재 값을 큐의 맨앞에 있는 빈칸의 좌표에 저장
					retmap[ny][nx] = retmap[y][x];
					// 현재 좌표를 0으로 바꾸고, 이제 빈칸이니까 큐에 저장
					retmap[y][x] = 0; q.push(make_pair(y, x));
				}
			}
		}
		// 나머지 방향도 맵을 탐색하는 방향만 바꿔주고 로직은 똑같음
	}
	else if (dir == 1) { // 아래로 이동
		for (int x = 0; x < n; x++) {
			// 1. 더하기
			int sum = 0; int by, bx;
			// 아래에서 위로 탐색
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
	else if (dir == 2) { // 왼쪽으로 이동
		for (int y = 0; y < n; y++) {
			// 1. 더하기
			int sum = 0; int by, bx;
			// 왼쪽에서 오른쪽으로 이동하면서 탐색
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
			// 2. 왼쪽 벽으로 밀기
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
	else { // 위로 이동
		for (int x = 0; x < n; x++) {
			// 1. 더하기
			int sum = 0; int by, bx;
			// 위에서 아래로 이동하면서 탐색
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
			// 2. 위쪽 벽으로 밀기
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
	// 이동완료된 맵을 리턴해준다.
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