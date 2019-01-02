#include <iostream>
#include <queue>
#define MAX 5
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

typedef struct Cell {
	int active;
	int inactive;
	bool dead;
	int time;
	Cell() { inactive = -1; }
	Cell(int a_, int i_, int d_, int t_) : active(a_), inactive(i_), dead(d_), time(t_){}
}Cell;

int n, m, k;
Cell map[MAX][MAX];
queue<pair<int, int>> q;

int main(void) {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int input; cin >> input;
				if (input) {
					q.push(make_pair(i + 2, j + 2));
					map[i + 3][j + 3] = Cell({ 0, input, false, 0 });
				}
			}
		}

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			// Ȱ��==��Ȱ�� && ���׾��� ==> ����
			if (map[y][x].active == map[y][x].inactive && !map[y][x].dead) {
				map[y][x].dead = true;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];

					// �׾��� �о�
					if (map[ny][nx].dead) continue; 
					// ���� ���ľ��Ѽ��ΰ��
					if (map[ny][nx].inactive == NULL) {
						map[ny][nx] = Cell({ 0, map[y][x].inactive, false, map[y][x].time + 1 });
						if(map[ny][nx].time <= k) q.push({ ny,nx });
					}
					// ���ÿ� �����ϴ°��
					else if (map[ny][nx].time == map[y][x].time) {
						if (map[y][x].inactive > map[ny][nx].inactive) map[ny][nx].inactive = map[y][x].inactive;
					}
				}
			}
			else { map[y][x].active += 1; map[y][x].time += 1; q.push({ y,x }); }
		}
		int ans = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (map[i][j].inactive - map[i][j].active >= 0) ans += 1;
			}
		}

		printf("#%d %d\n", t, ans);
	}
}