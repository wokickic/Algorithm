#include <iostream>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int n;
int ans = MAX;
vector<vector<int>> map, visit;
queue<pair<int, int>> q;

void dfs(int y, int x, int cnt) {
	visit[y][x] = 0; map[y][x] = cnt;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
			// 다음 좌표가 섬이고, 아직 방문 안했으면 이동
			if (map[ny][nx] == 1 && visit[ny][nx] == -1) dfs(ny, nx, cnt);
			// 다음 좌표가 바다이고, 아직 방문 안했으면 큐에 넣고, visit 방문처리
			else if (map[ny][nx] == 0 && visit[ny][nx] == -1) { q.push(make_pair(ny, nx)); visit[ny][nx] = 1; }
		}
	}
}

void bfs(int cnt) {	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		// 지금 방문한 곳의 이동거리가 ans보다 크면 다음 좌표로 이동
		if(visit[y][x] > ans) continue;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				// 현재 대륙이 아니면 ans에 지금 이동거리 저장
				if (map[ny][nx] != cnt && map[ny][nx] != 0) ans = visit[y][x];
				// 바다이고, 아직 방문 안했으면 거리 증가시켜주고 큐에 저장
				else if (map[ny][nx] == 0 && visit[ny][nx] == -1) {
					visit[ny][nx] = visit[y][x] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main(void) {
	cin >> n;
	int cnt = 1;
	visit = map = vector<vector<int>>(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == -1) {
				// 섬에 번호를 부여하고, 인접한 바다의 좌표를 저장하는 함수
				dfs(i, j, ++cnt);
				// 가장 가까운섬 찾기
				bfs(cnt);
			}
		}
	}
	printf("%d\n", ans);
}