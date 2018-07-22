#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 8방향 이동
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int n;
vector<vector<int>> map;

void bfs(int y, int x, int desy, int desx) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	map[y][x] = 0;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				// map이 -1이면 아직 방문 안함, 현재노드위치의 값에 1더해주고 큐에 넣음
				if (map[ny][nx] == -1) {
					q.push(make_pair(ny, nx));
					map[ny][nx] = map[y][x] + 1;
					// ny,nx값이 이동하려고하는 칸의 값과 같으면 
					// 최단거리 값을 찾았기 때문에 더이상 진행안하고 리턴
					if (ny == desy && nx == desx) return;
				}
			}
		}
	}
}

int main(void) {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int ny, nx, desx, desy; // 시작점, 종착점
		cin >> n;
		cin >> ny >> nx >> desy >> desx;
		
		// map을 -1로 초기화
		map = vector<vector<int>>(n, vector<int> (n, -1));		
		bfs(ny, nx, desy, desx);
		printf("%d\n", map[desy][desx]);
	}
}