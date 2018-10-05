#include <iostream>
#include <vector>
#include <queue>
#define MID 500
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, m, k;
int map[1000][1000];
queue<pair<int, int>> q;


int main(void) {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> map[MID + i][MID + j];
				if (map[MID + i][MID + j] = !0) q.push({ MID + i, MID + j });
			}

		while (k--) {
			while (!q.empty()) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];

				}
			}
		}
	}
}