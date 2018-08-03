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
					// ret에 다음 위치에서의 값과 ret값을 비교해서
					// 큰값을 ret에 저장 
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
			// %앞에 띄어쓰기 해줘야함
			// 띄어쓰기 안해주면 맨앞에 공백 입력받음
			scanf(" %1c", &map[i][j]);
			//cin >> map[i][j]; 이거도 가능하넹


	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 'L')
				// map이 'L'인 모든 위치에서 bfs를 수행하고
				// 리턴받은 값과 ans를 비교해서 큰값을 ans에저장
				ans = max(ans, bfs(i, j));
	
	printf("%d\n", ans);
}