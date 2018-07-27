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
vector<pair<int, int>> initVirus; // 바이러스 초기위치



int safeAreaCount(vector<vector<int>>& mapCopy) {
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mapCopy[i][j] == SAFE) ret++;
	return ret;
}

// 2차원 벡터의 주소를 리턴하기 위해서
// 리턴타입은 2차원 벡터
vector<vector<int>> bfs() { //바이러스 퍼뜨리는 함수
	queue<pair<int, int>> virus;
	vector<vector<int>> mapCopy = map; // map을 복사

	// 큐에 바이러스의 초기위치 넣음
	for (int i = 0; i < initVirus.size(); i++)
		virus.push(initVirus[i]);

	// 복사한맵에 바이러스 퍼뜨림
	while (!virus.empty()) {
		int y = virus.front().first;
		int x = virus.front().second;
		virus.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				// 안전구역이면 
				if (mapCopy[ny][nx] == SAFE) {
					// 바이러스로 바꿔줌
					mapCopy[ny][nx] = VIRUS;
					virus.push(make_pair(ny, nx));
				}
			}
		}
	}
	// 복사한 맵 리턴
	return mapCopy;
}

void dfs(int y, int x, int wallCnt) {
	if (wallCnt == 3) {
		// 3개의 벽을 세우면 bfs()로 바이러스를 퍼뜨림
		vector<vector<int>> mapCopy = bfs();

		// bfs()로 리턴 받은 맵을 이용해서 안전구역 최대값 구하기
		ans = max(ans, safeAreaCount(mapCopy));
		return;
	}

	for (int i = y; i < n; i++)
		for (int j = ((i == y) ? x : 0); j < m; j++) {
			if (map[i][j] == SAFE) {
				map[i][j] = WALL; // 안전구역이면 벽세우고
				dfs(i, j + 1, wallCnt + 1);
				map[i][j] = SAFE; // 탐색을 마치고 나오면 다시 벽 복구 
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
			// 바이러스를 벡터에 넣는 이유
			// 바이러스 퍼뜨릴때 BFS() 이용해서 퍼뜨림, 큐에 넣으면 바이러스 위치 사라짐
			// 매번 BFS()실행할때 큐에 바이러스의 초기값을 넣고 시작
			if (map[i][j] == VIRUS) initVirus.push_back(make_pair(i, j));
		}

	dfs(0, 0, 0);
	printf("%d\n", ans);
}