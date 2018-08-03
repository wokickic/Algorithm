#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
int n, m;
int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

vector<vector<char>> map;
vector<vector<int>> visit;

int bfs(int y, int x) {
	int ret = 0;
	visit = vector<vector<int>>(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = 0;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				if (map[ny][nx] == 'L' && visit[ny][nx] == -1) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = visit[y][x] + 1;
					// ret�� ���� ��ġ������ ���� ret���� ���ؼ�
					// ū���� ret�� ���� 
					ret = max(ret, visit[ny][nx]);
				}
			}
		}
	}
	return ret;
}

int main(void) {
	cin >> n >> m;
	map = vector<vector<char>>(n, vector<char>(m));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			// %�տ� ���� �������
			// ���� �����ָ� �Ǿտ� ���� �Է¹���
			scanf(" %1c", &map[i][j]);
			//cin >> map[i][j]; �̰ŵ� �����ϳ�


	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 'L')
				// map�� 'L'�� ��� ��ġ���� bfs�� �����ϰ�
				// ���Ϲ��� ���� ans�� ���ؼ� ū���� ans������
				ans = max(ans, bfs(i, j));
	
	printf("%d\n", ans);
}