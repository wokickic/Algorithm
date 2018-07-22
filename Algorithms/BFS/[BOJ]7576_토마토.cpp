#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int n, m;
vector<vector<int>> map, visit;
queue<pair<int, int>> q;

int main(void) {
	cin >> n >> m;
	// create map
	map = visit = vector<vector<int>>(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) q.push(make_pair(i, j));
		}
	}
	
	int y = q.front().first;
	int x = q.front().second;
	visit[y][x] = true;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
				if (map[ny][nx] == 0 && !visit[ny][nx]) {
					visit[ny][nx] = 1;
					map[ny][nx] = map[y][x] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) { printf("%d\n", -1); return 0; }
			ans = max(ans, map[i][j]);
		}
	}
	printf("%d\n", ans - 1);
}