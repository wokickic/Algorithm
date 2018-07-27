#include <iostream>
#include <vector>
#include <queue>

#define max(a, b) ((a > b) ? (a) : (b))
#define SAFE 0
#define WALL 1
#define VIRUS 2
using namespace std;

int n, m, ans;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<int>> map;
vector<pair<int, int>> initVirus; // ���̷��� �ʱ���ġ



int safeAreaCount(vector<vector<int>>& mapCopy) {
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mapCopy[i][j] == SAFE) ret++;
	return ret;
}

// 2���� ������ �ּҸ� �����ϱ� ���ؼ�
// ����Ÿ���� 2���� ����
vector<vector<int>> bfs() { //���̷��� �۶߸��� �Լ�
	queue<pair<int, int>> virus;
	vector<vector<int>> mapCopy = map; // map�� ����

	// ť�� ���̷����� �ʱ���ġ ����
	for (int i = 0; i < initVirus.size(); i++)
		virus.push(initVirus[i]);

	// �����Ѹʿ� ���̷��� �۶߸�
	while (!virus.empty()) {
		int y = virus.front().first;
		int x = virus.front().second;
		virus.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				// ���������̸� 
				if (mapCopy[ny][nx] == SAFE) {
					// ���̷����� �ٲ���
					mapCopy[ny][nx] = VIRUS;
					virus.push(make_pair(ny, nx));
				}
			}
		}
	}
	// ������ �� ����
	return mapCopy;
}

void dfs(int y, int x, int wallCnt) {
	if (wallCnt == 3) {
		// 3���� ���� ����� bfs()�� ���̷����� �۶߸�
		vector<vector<int>> mapCopy = bfs();

		// bfs()�� ���� ���� ���� �̿��ؼ� �������� �ִ밪 ���ϱ�
		ans = max(ans, safeAreaCount(mapCopy));
		return;
	}

	for (int i = y; i < n; i++)
		for (int j = ((i == y) ? x : 0); j < m; j++) {
			if (map[i][j] == SAFE) {
				map[i][j] = WALL; // ���������̸� �������
				dfs(i, j + 1, wallCnt + 1);
				map[i][j] = SAFE; // Ž���� ��ġ�� ������ �ٽ� �� ���� 
			}
		}
}

int main(void) {
	cin >> n >> m;
	ans = 0;
	// create map
	map = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			// ���̷����� ���Ϳ� �ִ� ����
			// ���̷��� �۶߸��� BFS() �̿��ؼ� �۶߸�, ť�� ������ ���̷��� ��ġ �����
			// �Ź� BFS()�����Ҷ� ť�� ���̷����� �ʱⰪ�� �ְ� ����
			if (map[i][j] == VIRUS) initVirus.push_back(make_pair(i, j));
		}

	dfs(0, 0, 0);
	printf("%d\n", ans);
}