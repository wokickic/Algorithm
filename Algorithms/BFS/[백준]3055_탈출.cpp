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
	// 물이 없는경우도 있기때문에 MAX로 초기화
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

// 물이 퍼뜨린거보다 먼저 가면 물이 차기 전이기때문에 
// 이동가능/ w_visit[y][x] > s_visit[y][x]이면 이동가능 
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
				// map이 '.' 이고 아직 방문전이면 이동 가능
				// 또는 D를 만나면 탈출가능
				if ((map[ny][nx] == '.' && s_visit[ny][nx] == -1) || map[ny][nx] == 'D') {
					// w_visit[][]을 -1로 초기화 하면, 물이 없는경우 아래의 if문으로 안들어감
					// 그래서 987654321과 같은 큰숫자로 초기화해줌
					if (s_visit[y][x] + 1 < w_visit[ny][nx]) {
						q.push(make_pair(ny, nx));
						s_visit[ny][nx] = s_visit[y][x] + 1;
						//D를 만나면 D를 만났을때 시간을 리턴
						if (ny == D.first && nx == D.second) return s_visit[ny][nx];
					}
				}
			}
		}
	}
	// while()문이 종료될때까지 리턴 못한거면 출구 못찾음 
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

	water_bfs(); // 먼저 물을 bfs()로 물을 퍼뜨린다
	int ans = s_bfs(S.first, S.second);
	if (ans == -1) printf("KAKTUS\n");
	else printf("%d\n", ans);
}