#include <iostream>
#include <vector>
#define min(a, b) ((a) > (b) ? (b) : (a))
#define INF 987654321
#define RED 0
#define BLUE 1
#define NFIND false
#define FIND true
using namespace std;

//          오 아 왼 위
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int n, m;
int ans;

typedef struct Point {
	int y, x;
	Point() {}
	Point(int y_, int x_) : y(y_), x(x_) {}
};

vector<vector<char>> map;
Point hole;

// 빨간공이 기준, 빨간공의 진행방향으로 파란색공이 있으면 파란공 먼저 굴리고
// 아니면 빨간공 먼저 굴림
int findBall(Point& red, Point& blue, int dir) {
	int y = red.y;
	int x = red.x;
	for (; map[y][x] != '#';) {
		y = y + dy[dir];
		x = x + dx[dir];
		if (y == blue.y && x == blue.x) return BLUE;
	}
	return RED;
}
// ball : 굴릴공, stop : 굴려진공 or 다음에 굴릴공, dir : 굴릴방향
bool move(Point& ball, Point stop, int dir) {
	int y = ball.y;
	int x = ball.x;
	// #이 아니고 다른공이 아니면 다음 반복
	for (;;) {
		y = y + dy[dir];
		x = x + dx[dir];
		// 구멍 만나면 빼낼수있다 리턴,
		// y,x 좌표에는 n,m값을 넣어서 다음에 굴려지는 공이 구멍에 빠지는지 판단
		if (y == hole.y && x == hole.x) { ball.y = n; ball.x = m; return FIND; }

		// 다른 공과 좌표가 겹치거나 벽에 부딪히면 구멍 못찾았다고 리턴
		if ((y == stop.y && x == stop.x ) ||map[y][x] == '#')  return NFIND;

		// 위의 두경우에 안걸리면 이동한 값을 ball에 갱신시켜줌
		ball.y = y; ball.x = x;
	}
	return NFIND;
}
//         dir은 현재방향
int getDir(int dir, int i) {
	// dir이 0(오른쪽), 2(왼쪽)면 좌우 탐색
	if (dir == 0 || dir == 2) {
		// 다음방향은 아래쪽
		if (i == 0) return 1;
		// 위쪽
		else return 3;
	}
	else {
	// dir이 1(아래), 3(위)면 현재 아래, 위 탐색
		// 다음 방향은 오른쪽
		if (i == 0) return 0;
		// 왼쪽
		else return 2;
	}
}

void dfs(Point red, Point blue, int dir, int cnt) {
	if (cnt > 10) return;
	// 두방향만 탐색
	// 현재 방향이 -> 이면 다음에 탐색할 방향은
	// <-, -> 방향을 탐색할 필요없음 위, 아래만 탐색해보면댐
	for (int i = 0; i < 2; i++) {
		Point nred = red;
		Point nblue = blue;
		bool r_flag, b_flag;
		
		// 어떤구슬 먼저 굴릴지 찾아야댐
		int first = findBall(red, blue, dir);
		if (first == RED) {
			// 빨간거먼저 굴리기
			// nred는 이동하고 이동완료된 좌표로 바뀜
			r_flag = move(nred, blue, dir);
			// 파란공 굴릴때 red가 아닌 이동이 완료된 nred를 변수로 보내줘야한다.
			b_flag = move(nblue, nred, dir);
		}
		else {
			// 파란거먼저 굴리기
			b_flag = move(nblue, red, dir);
			r_flag = move(nred, nblue, dir);
		}
		// 공이 2개다 빠진경우 -> 실패
		if (r_flag == FIND && b_flag == FIND) return;
		// 파란공만 빠진경우 -> 실패
		else if (r_flag == NFIND && b_flag == FIND) return;
		// 빨간공만 빠진경우 -> 성공
		else if (r_flag == FIND && b_flag == NFIND) { ans = min(ans, cnt); return; }

		// 위의 경우 아무것도 안걸리면 다음 방향으로 기울여봄
		dfs(nred, nblue, getDir(dir, i), cnt + 1);
	}
}

int main(void) {
	cin >> n >> m;
	map = vector<vector<char>>(n, vector<char>(m));
	Point red, blue;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') red = { i, j };
			else if (map[i][j] == 'B') blue = { i, j };
			else if (map[i][j] == 'O') hole = { i, j };
		}
	
	ans = INF;
	// 초반에 4방향 탐색
	for (int i = 0; i < 4; i++)
		dfs(red, blue, i, 1);
	
	printf("%d\n", (ans == INF ? -1 : ans));
}