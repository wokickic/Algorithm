#include <iostream>
#include <vector>
#include <queue>
#define MID 500
using namespace std;
typedef struct cell {
	int die, up, down;
	int check[6];
	cell() {}
};
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, m, k;
cell map[1000][1000];
queue<pair<int, int>> q;


int main(void) {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int in; cin >> in;
				if (in != 0) {
					map[i][j].down = in;
					q.push({ i, j });
				}
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