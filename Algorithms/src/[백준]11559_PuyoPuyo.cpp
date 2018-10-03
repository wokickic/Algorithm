#include <iostream>
#include <queue>
#define ROW 12
#define COL 6
#define DOT '.'
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char map[ROW][COL];

queue<pair<int, int>> bfs(int y, int x, char puyo, bool (*visit)[COL]) {
	queue<pair<int, int>> q, ret;
	q.push(make_pair(y, x)); // bfs Ž����
	ret.push(make_pair(y, x));// return ��
	visit[y][x] = true;

	while (!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < ROW && nx < COL) {
				if (map[ny][nx] == puyo && !visit[ny][nx]) {
					q.push(make_pair(ny, nx));
					ret.push(make_pair(ny, nx));
					visit[ny][nx] = true;
				}
			}
		}
	}
	// ���Ű����� �ѿ䰡 ����Ǿ��ִ� ť�� ����
	return ret;
}

int go(int cnt) {
	while (1) {
		// �ݺ����� �湮ó�����ִ� �迭�� �����.
		bool visit[ROW][COL] = { 0, };

		// ť�� �����ϴ� ť -> ���� ������ �ѿ並 �����ϴ� ť
		queue<queue<pair<int, int>>> qq;
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				// ���� �湮���ϰ� �����̸� bfsŽ
				if (map[i][j] == DOT || visit[i][j]) continue;
				// ���� ������ ť�� ���� ����
				queue<pair<int, int>> ret = bfs(i, j, map[i][j], visit);
				// ���Ϲ��� ť�� ũ�Ⱑ 4�̻��̸� ���� ����, ť�� ť�� ����
				if (ret.size() >= 4) qq.push(ret);
			}
		}
		// ť�� ��������� ���̻� �����Ҽ� �ִ� �ѿ䰡 ���⶧���� cnt����
		if (qq.empty()) return cnt;
		// �׷��� ������, ���Ű����� �ѿ䰡 �����ϱ� ������ cnt����������
		cnt++;
		while (!qq.empty()) {
			// �����ϴ� �۾�
			// ť���� ť�� �̾ƿ´�.
			queue<pair<int, int>> q = qq.front();
			qq.pop();
			while (!q.empty()) {
				//�ѿ並 '.'���� �ٲ���
				int y = q.front().first; 
				int x = q.front().second;
				map[y][x] = DOT; q.pop();
			}
		}
		// �Ʒ��� �����
		//(11, 5) ~ (11,0), (10,5) ~ (10,0) ... ������ ���鼭 ����� ä���
		for (int i = COL - 1; i >= 0; i--) {
			queue<pair<int, int>> q;
			for (int j = ROW - 1; j >= 0; j--) {
				// ��ĭ �߰��ϸ� ť���ְ�
				if (map[j][i] == DOT) q.push(make_pair(j, i));
				// ��ĭ�� �ƴϰ�, ť�� �Ⱥ��������(ť�� ���������, ���� ��ĭ ����)
				else if (map[j][i] != DOT && !q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					// �ѿ並 ��ĭ�� �̵���Ű��, �̵���Ų ���� ��ĭ���� ä���, ť������
					map[y][x] = map[j][i];
					map[j][i] = DOT;
					q.push(make_pair(j, i));
				}
			}
		}
	}
	return cnt;
}

int main(void) {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			cin >> map[i][j];

	printf("%d\n", go(0));
}