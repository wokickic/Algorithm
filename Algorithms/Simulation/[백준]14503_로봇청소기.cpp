#include <iostream>
#include <vector>
#define CLEAN 2
#define WALL 1
#define NCLEAN 0
using namespace std;

//          북 동 남 서
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int m, n;
vector<vector<int>> map;

int move(int r, int c, int dir) {
	int cnt = 0;
	int y = r;
	int x = c;
	int d = dir;

	// 처음위치 청소, 청소칸의 개수 1증가
	map[y][x] = CLEAN; cnt++;

	while (1) {
		// dircheck : 4방향확인해서, 다음칸으로 이동할지, 후진할지 결정하는 변수
		// nd : 다음 방향저장, d에 안하고 nd에하는 이유는 후진할때 현재방향 기준으로 해야하기때문에
		int dircheck = 0; int nd = d;
		for (int i = 0; i < 4; i++) {
			// 왼쪽으로 이동
			nd = (nd + 3) % 4;
			int ny = y + dy[nd];
			int nx = x + dx[nd];
			// 다음 좌표가 청소안했으면 y, x, d를 이동한 값으로 바꿔주고 반복문 종료
			if (map[ny][nx] == NCLEAN) {
				y = ny; x = nx; d = nd;
				break;
			}
			// 이동한 좌표가 이미청소 완료 거나 벽이라 청소못한경우
			// 1증가 시켜준다
			dircheck++;
		}

		// dircheck != 4이면 청소 안한 구역을 찾은것이기 때문에 
		// (y,x)청소마킹하고 다음 반복실행
		if (dircheck != 4) { map[y][x] = CLEAN; cnt++; }
		
		//
		else {
			// back는 현재 방향을 바라보고 후진하는 좌표
			int back = (d + 2) % 4;
			int ny = y + dy[back];
			int nx = x + dx[back];

			// 후진했을때 벽이면 더이상 이동이 불가능하기때문에 cnt 리턴해주고 함수종료
			if (map[ny][nx] == WALL) return cnt;
			// 그렇지 않으면 (y,x)를 후진한 좌표로 업데이트 해주고, 방향은 현재방향 유지
			else { y = ny; x = nx; }
		}
	}
}

int main(void) {
	cin >> n >> m;
	int r, c, d; cin >> r >> c >> d;

	map = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	printf("%d\n", move(r, c, d));
}