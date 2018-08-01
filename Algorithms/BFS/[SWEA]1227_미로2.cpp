#include <iostream>
#include <vector>
#include <queue>
#define N 100
#define vv vector<vector<int>>&
using namespace std;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

bool bfs(pair<int, int> s, vv m, vv vi) {
	queue<pair<int, int>> q;
	q.push(make_pair(s.first, s.second));
	vi[s.first][s.second] = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
				if (m[nr][nc] == 3) return true; // �ⱸ ã��
				else {
					if (m[nr][nc] == 0 && vi[nr][nc] == 0) { //��� ť�� �߰�
						vi[nr][nc] = 1;
						q.push(make_pair(nr, nc));
					}
				}
			}
		}
	}
	return false;
}

int main(void) {
	for (int i = 1; i <= 10; i++) {
		int t; cin >> t;
		vector<vector<int>> map(N, vector<int>(N));
		vector<vector<int>> visit(N, vector<int>(N, 0));
		pair<int, int> start;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// ���� ��� scanf�� �޾ƾߴ�
				scanf("%1d", &map[i][j]); 
				if (map[i][j] == 2) { start.first = i; start.second = j; }
			}
		}
		printf("#%d %d\n", t, (bfs(start, map, visit) ? 1 : 0));
	}
}