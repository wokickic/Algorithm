#include <iostream>
#include <vector>
#include <queue>
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, w, h, ans;
vector<vector<int>> init_map;

vector<vector<int>> remove(int x, vector<vector<int>> ret) {
	queue<pair<int, int>> q;
	int y;
	for (y = 0; y < h; y++) {
		if (ret[y][x] == 0) continue;
		q.push({ y, x });
		break;
	}

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		int len = ret[y][x] - 1;
		ret[y][x] = 0;
		q.pop();
		if (len == 0) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y;
			int nx = x;
			for (int j = 0; j < len; j++) {
				ny = ny + dy[i];
				nx = nx + dx[i];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w) break;
				if (ret[ny][nx] != 0) q.push({ ny, nx });
			}
		}
	}
	
	// πÿ¿∏∑Œ ∂Ø±‚±‚
	for (int j = 0; j < w; j++) {
		queue<pair<int, int>> qq;
		for (int i = h - 1; i >= 0; i--) {
			if (ret[i][j] == 0) qq.push({ i, j });
			else if (!qq.empty()) {
				y = qq.front().first;
				x = qq.front().second; qq.pop();
				ret[y][x] = ret[i][j];
				ret[i][j] = 0; 
				qq.push({ i, j });
			}
		}
	}
	return ret;
}

void go(int x, int depth, vector<vector<int>>& map) {
	if (x < 0 || x >= w) return;
	if (depth == n) {
		int cnt = 0;
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++)
				if (map[i][j] != 0) cnt++;

		ans = min(ans, cnt);
		return;
	}
	
	vector<vector<int>> copy_map = remove(x, map);

	for (int i = 0; i < w; i++) 
		go(i, depth + 1, copy_map);
}

int main(void) {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> w >> h;
		init_map = vector<vector<int>>(h, vector<int>(w));
		ans = 987654321;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> init_map[i][j];
	
		for (int i = 0; i < w; i++)
			go(i, 0, init_map);

		printf("#%d %d\n", t, ans);
	}
}

