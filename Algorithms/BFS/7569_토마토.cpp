#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
//			 위 밑 오  앞 왼 뒤
int dz[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 0, 1, 0, -1 };
int dx[] = { 0, 0, 1, 0, -1, 0 };

int n, m, h;
vector<vector<vector<int>>> map, visit;

// x,y,z를 저장할 구조체
typedef struct Point {
	int x, y, z;
	// 생성자
	Point() = default;
	Point(int z_, int y_, int x_) : z(z_), y(y_), x(x_) {}
};

int main(void) {
	cin >> m >> n >> h;
	
	// 3차원 벡터생성
	visit = map = vector<vector<vector<int>>>(h, vector<vector<int>>(n, vector<int>(m, -1)));
	queue<Point> q;

	// create map
	// 하나라도 안익은게있는 경우 true값으로 
	bool zeroFlag = false;
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> map[k][i][j];
				// 0이 하나라도 있으면 플래그는 true
				if (map[k][i][j] == 0) zeroFlag = true;
				if (map[k][i][j] == 1) { 
					q.push(Point(k, i, j)); 
					visit[k][i][j] = 0; 
				}
			}
	//  저장될때부터 모두 익어있는 경우 0을 출력하고 종료 
	if (!zeroFlag) { printf("%d\n",zeroFlag); return 0;}

	// bfs
	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz >= 0 && ny >= 0 && nx >= 0 && nz < h && ny < n && nx < m) {
				if (map[nz][ny][nx] == 0 && visit[nz][ny][nx] == -1) {
					q.push(Point(nz, ny, nx));
					visit[nz][ny][nx] = visit[z][y][x] + 1;
				}
			}
		}
	}

	// 답찾기
	int ans = 0;
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				// visit과 map둘다 체크해줘야함!!!!!
				// map의 값이 0이고 visit의 값이-1 인경우는 
				// 토마토가 안익었는대 방문을 안함 따라서 안익은 토마토 존재
				// visit이 -1 이지만 map의값이 -1인경우땜에 틀렸음.
				if (visit[k][i][j] == -1 && map[k][i][j] == 0) { printf("-1\n"); return 0; }
				ans = max(ans, visit[k][i][j]);
			}
	printf("%d\n", ans);
}