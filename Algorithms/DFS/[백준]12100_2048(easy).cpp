#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int n, ans;

// ������ �������� �� ���ϱ�
vector<vector<int>> move(int dir, vector<vector<int>>& map) {
	vector<vector<int>> retmap = map;

	if (dir == 0) { // ���������� �̵���ų��
		for (int y = 0; y < n; y++) {
			// 1. ���ϱ�
			// ���ϴ� ������ �����ʿ��� �������� �̵��ϸ鼭
			// ������ ���� ��ġ�ϸ� �����ְ� �׷��� ������ �����ǰ��� 
			// ���簪���� �ٲ���
			int sum = 0; int by, bx;
			// �����ʿ��� �������� �̵�
			for (int x = n - 1; x >= 0; x--) {
				if (retmap[y][x] == 0) continue;
				if (sum == 0) { 
					sum = retmap[y][x]; 
					// ���� ���̶� ���ؼ� �����ϱ����� ������ġ ����
					by = y; bx = x;
				}
				else {
					// ������ ���� ������ġ�� ���� ������
					if (sum == retmap[y][x]) {
						// 2���ؼ� �����ϰ�
						retmap[by][bx] = sum * 2;
						// ������ġ�� 0���� ���ְ� sum�� �ٽ� 0���� �ʱ�ȭ
						retmap[y][x] = 0;
						sum = 0;
					}
					// ������ ���� ���� ��ġ�� ���� �ٸ���
					// ���� ���� sum���� ����
					else { sum = retmap[y][x]; by = y; bx = x; }
				}
			}
			// 2. ������ ������ �б�
			// ť���� ��ĭ�� ��ǥ�� ����
			queue<pair<int, int>>q;
			// �����ʿ��� �������� Ž��
			for (int x = n - 1; x >= 0; x--) {
				// ��ĭ�� ��ǥ ť�� ����
				if (retmap[y][x] == 0) { q.push(make_pair(y, x)); continue; }
				if (retmap[y][x] != 0 && !q.empty()) {
					// ��ĭ�� �ƴϰ� ť�� �Ⱥ�� ������
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop();
					// ���� ���� ť�� �Ǿտ� �ִ� ��ĭ�� ��ǥ�� ����
					retmap[ny][nx] = retmap[y][x];
					// ���� ��ǥ�� 0���� �ٲٰ�, ���� ��ĭ�̴ϱ� ť�� ����
					retmap[y][x] = 0; q.push(make_pair(y, x));
				}
			}
		}
		// ������ ���⵵ ���� Ž���ϴ� ���⸸ �ٲ��ְ� ������ �Ȱ���
	}
	else if (dir == 1) { // �Ʒ��� �̵�
		for (int x = 0; x < n; x++) {
			// 1. ���ϱ�
			int sum = 0; int by, bx;
			// �Ʒ����� ���� Ž��
			for (int y = n - 1; y >= 0; y--) {
				if (retmap[y][x] == 0) continue;
				if (sum == 0) {
					sum = retmap[y][x];
					by = y; bx = x;
				}
				else {
					if (sum == retmap[y][x]) {
						retmap[by][bx] = sum * 2;
						retmap[y][x] = 0;
						sum = 0;
					}
					else { sum = retmap[y][x]; by = y; bx = x; }
				}
			}
			// 2. �Ʒ��� ������ �б�
			queue<pair<int, int>>q;
			for (int y = n - 1; y >= 0; y--) {
				if (retmap[y][x] == 0) { q.push(make_pair(y, x)); continue; }
				if (retmap[y][x] != 0 && !q.empty()) {
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop();
					retmap[ny][nx] = retmap[y][x];
					retmap[y][x] = 0; q.push(make_pair(y, x));
				}
			}
		}
	}
	else if (dir == 2) { // �������� �̵�
		for (int y = 0; y < n; y++) {
			// 1. ���ϱ�
			int sum = 0; int by, bx;
			// ���ʿ��� ���������� �̵��ϸ鼭 Ž��
			for (int x = 0; x < n; x++) {
				if (retmap[y][x] == 0) continue;
				if (sum == 0) {
					sum = retmap[y][x];
					by = y; bx = x;
				}
				else {
					if (sum == retmap[y][x]) {
						retmap[by][bx] = sum * 2;
						retmap[y][x] = 0;
						sum = 0;
					}
					else { sum = retmap[y][x]; by = y; bx = x; }
				}
			}
			// 2. ���� ������ �б�
			queue<pair<int, int>>q;
			for (int x = 0; x < n; x++) {
				if (retmap[y][x] == 0) { q.push(make_pair(y, x)); continue; }
				if (retmap[y][x] != 0 && !q.empty()) {
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop();
					retmap[ny][nx] = retmap[y][x];
					retmap[y][x] = 0; q.push(make_pair(y, x));
				}
			}
		}
	}
	else { // ���� �̵�
		for (int x = 0; x < n; x++) {
			// 1. ���ϱ�
			int sum = 0; int by, bx;
			// ������ �Ʒ��� �̵��ϸ鼭 Ž��
			for (int y = 0; y < n; y++) {
				if (retmap[y][x] == 0) continue;
				if (sum == 0) {
					sum = retmap[y][x];
					by = y; bx = x;
				}
				else {
					if (sum == retmap[y][x]) {
						retmap[by][bx] = sum * 2;
						retmap[y][x] = 0;
						sum = 0;
					}
					else { sum = retmap[y][x]; by = y; bx = x; }
				}
			}
			// 2. ���� ������ �б�
			queue<pair<int, int>>q;
			for (int y = 0; y < n; y++) {
				if (retmap[y][x] == 0) { q.push(make_pair(y, x)); continue; }
				if (retmap[y][x] != 0 && !q.empty()) {
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop();
					retmap[ny][nx] = retmap[y][x];
					retmap[y][x] = 0; q.push(make_pair(y, x));
				}
			}
		}
	}
	// �̵��Ϸ�� ���� �������ش�.
	return retmap;
}

void dfs(int dir, int cnt, vector<vector<int>> map) {
	if (cnt == 5) {
		// �ִ� �� ���ϱ�
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!map[i][j]) continue;
				ans = max(ans, map[i][j]);
			}
		return;
	}

	for (int i = 0; i < 4; i++) {
		vector<vector<int>> copymap = move(i, map);
		dfs(i, cnt + 1, copymap);
	}
}

int main(void) {
	cin >> n; ans = 0;
	vector<vector<int>> map (n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	
	dfs(0, 0, map);
	printf("%d\n", ans);
} 