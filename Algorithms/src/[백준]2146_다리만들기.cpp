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
			// ���� ��ǥ�� ���̰�, ���� �湮 �������� �̵�
			if (map[ny][nx] == 1 && visit[ny][nx] == -1) dfs(ny, nx, cnt);
			// ���� ��ǥ�� �ٴ��̰�, ���� �湮 �������� ť�� �ְ�, visit �湮ó��
			else if (map[ny][nx] == 0 && visit[ny][nx] == -1) { q.push(make_pair(ny, nx)); visit[ny][nx] = 1; }
		}
	}
}

void bfs(int cnt) {	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		// ���� �湮�� ���� �̵��Ÿ��� ans���� ũ�� ���� ��ǥ�� �̵�
		if(visit[y][x] > ans) continue;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				// ���� ����� �ƴϸ� ans�� ���� �̵��Ÿ� ����
				if (map[ny][nx] != cnt && map[ny][nx] != 0) ans = visit[y][x];
				// �ٴ��̰�, ���� �湮 �������� �Ÿ� ���������ְ� ť�� ����
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
				// ���� ��ȣ�� �ο��ϰ�, ������ �ٴ��� ��ǥ�� �����ϴ� �Լ�
				dfs(i, j, ++cnt);
				// ���� ���� ã��
				bfs(cnt);
			}
		}
	}
	printf("%d\n", ans);
}