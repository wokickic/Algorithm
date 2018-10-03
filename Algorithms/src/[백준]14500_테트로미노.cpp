#include <iostream>
#include <vector>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
int n, m, ans;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
vector<vector<int>> map, visit;

void dfs(int y, int x, int sum, int depth) {
	if (depth == 4) {
		ans = MAX(ans, sum);
		return;
	}

	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
			if (!visit[ny][nx]) dfs(ny, nx, sum + map[ny][nx], depth + 1);
		}
	}
	visit[y][x] = false;
}

void checkOther(int y, int x) {
	if (x + 1 < m && x + 2 < m && y - 1 >= 0) ans = MAX(ans, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 1]);
	if (x + 1 < m && x + 2 < m && y + 1 < n) ans = MAX(ans, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1]);
	if (y + 1 < n && y + 2 < n && x + 1 < m) ans = MAX(ans, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1]);
	if (y + 1 < n && y + 2 < n && x - 1 >= 0) ans = MAX(ans, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x - 1]);
}

int main(void) {
	cin >> n >> m;
	map = visit = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, map[i][j], 1);
			// dfs빠져나오면 ㅗ 모양에 대해서 수행하기
			checkOther(i, j);
		}
	}
	printf("%d\n", ans);
}