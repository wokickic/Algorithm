#include <iostream>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int n, m;

vector<vector<char>> map;
pair<int, int> S, D;
vector<pair<int, int>> water;
vector<vector<int>> w_visit, s_visit;

void water_bfs() {
	queue<pair<int, int>> q;
	// ���� ���°�쵵 �ֱ⶧���� MAX�� �ʱ�ȭ
	w_visit = vector<vector<int>>(n, vector<int>(m, MAX));

	int y, x;
	for (int i = 0; i < water.size(); i++) {
		y = water[i].first;
		x = water[i].second;
		q.push(make_pair(y, x));
		w_visit[y][x] = 0;
	}

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				if (map[ny][nx] == '.' && w_visit[ny][nx] == MAX) {
					q.push(make_pair(ny, nx));
					w_visit[ny][nx] = w_visit[y][x] + 1;
				}
			}
		}
	}
}

// ���� �۶߸��ź��� ���� ���� ���� ���� ���̱⶧���� 
// �̵�����/ w_visit[y][x] > s_visit[y][x]�̸� �̵����� 
int s_bfs(int y, int x) {
	queue<pair<int, int>> q;
	s_visit = vector<vector<int>>(n, vector<int>(m, -1));
	q.push(make_pair(y, x));
	s_visit[y][x] = 0;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				// map�� '.' �̰� ���� �湮���̸� �̵� ����
				// �Ǵ� D�� ������ Ż�Ⱑ��
				if ((map[ny][nx] == '.' && s_visit[ny][nx] == -1) || map[ny][nx] == 'D') {
					// w_visit[][]�� -1�� �ʱ�ȭ �ϸ�, ���� ���°�� �Ʒ��� if������ �ȵ�
					// �׷��� 987654321�� ���� ū���ڷ� �ʱ�ȭ����
					if (s_visit[y][x] + 1 < w_visit[ny][nx]) {
						q.push(make_pair(ny, nx));
						s_visit[ny][nx] = s_visit[y][x] + 1;
						//D�� ������ D�� �������� �ð��� ����
						if (ny == D.first && nx == D.second) return s_visit[ny][nx];
					}
				}
			}
		}
	}
	// while()���� ����ɶ����� ���� ���ѰŸ� �ⱸ ��ã�� 
	return -1;
}

int main(void) {
	cin >> n >> m;
	map = vector<vector<char>>(n, vector<char>(m));

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') D = make_pair(i, j);
			if (map[i][j] == 'S') S = make_pair(i, j);
			if (map[i][j] == '*') water.push_back(make_pair(i, j));
		}

	water_bfs(); // ���� ���� bfs()�� ���� �۶߸���
	int ans = s_bfs(S.first, S.second);
	if (ans == -1) printf("KAKTUS\n");
	else printf("%d\n", ans);
}