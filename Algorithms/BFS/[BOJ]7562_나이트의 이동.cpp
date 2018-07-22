#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 8���� �̵�
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
				// map�� -1�̸� ���� �湮 ����, ��������ġ�� ���� 1�����ְ� ť�� ����
				if (map[ny][nx] == -1) {
					q.push(make_pair(ny, nx));
					map[ny][nx] = map[y][x] + 1;
					// ny,nx���� �̵��Ϸ����ϴ� ĭ�� ���� ������ 
					// �ִܰŸ� ���� ã�ұ� ������ ���̻� ������ϰ� ����
					if (ny == desy && nx == desx) return;
				}
			}
		}
	}
}

int main(void) {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int ny, nx, desx, desy; // ������, ������
		cin >> n;
		cin >> ny >> nx >> desy >> desx;
		
		// map�� -1�� �ʱ�ȭ
		map = vector<vector<int>>(n, vector<int> (n, -1));		
		bfs(ny, nx, desy, desx);
		printf("%d\n", map[desy][desx]);
	}
}