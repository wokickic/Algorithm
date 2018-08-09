#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#define APPLE 1
#define SNAKE 2
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

vector<vector<int>> map;
// 뱀의 방향정보 저장하는 큐
queue<pair<int, char>> snakeDir;

int n;

int getDir(int dir, char roDir) {
	if (roDir == 'L') dir = (dir - 1 < 0 ? 3 : dir - 1);
	else dir = (dir + 1 > 3 ? 0 : dir + 1);
	return dir;
}

int move() {
	// 뱀을 deque라는 자료구조를 사용해서 선언해줌
	// deque는 벡터와 큐를 합쳐놓은 것과 비슷한 자료구조
	// front와 back 양쪽에서 push와 pop이 가능함
	deque<pair<int, int>> snake;
	// front를 뱀의 머리, back을 뱀의 꼬리라고 하겠음
	snake.push_back(make_pair(1, 1));

	int y, x;
	int time = 0;
	int dir = 0;
	int roCnt = snakeDir.front().first;
	char roDir = snakeDir.front().second; 
	snakeDir.pop();
	y = x = 1;
	map[y][x] = SNAKE;

	while (1) {
		y = y + dy[dir];
		x = x + dx[dir];
		time += 1;

		// 이동한 좌표가 벽을 만나면 return
		if (y == 0 || y  == (n + 1) || x == 0 || x == (n + 1)) return time;

		// 이동한 좌표에 뱀이있으면 return
		if (map[y][x] == SNAKE) return time;

		// 이동한 좌표에 사과가 있는경우
		if (map[y][x] == APPLE) {
			// 해당좌표를 뱀으로 바꿔주고
			map[y][x] = SNAKE;
			// 좌표를 front해줘서 뱀의 길이가 늘어남
			snake.push_front(make_pair(y, x));
		}
		else {
			// 사과 없으면 이동좌표를 뱀으로 바꾸고 
			map[y][x] = SNAKE;
			// front로 머리 좌표 이동
			snake.push_front(make_pair(y, x));
			// map에서 꼬리가 있는 부분은 빈칸으로 바꿔줌
			map[snake.back().first][snake.back().second] = 0;
			// 꼬리부분을 pop해줘서 뱀의 길이는 유지한체 이동
			snake.pop_back();
		}
		
		// 이동방향 체크
		if (time == roCnt) {
			dir = getDir(dir, roDir);
			if (!snakeDir.empty()) {
				roCnt = snakeDir.front().first;
				roDir = snakeDir.front().second;
				snakeDir.pop();
			}
		}
	}

	return 0;
}

int main(void) {
	cin >> n;
	int k; cin >> k;
	
	// map을 만들때 1,1에서 시작하기위해서 n이 6이면 8 x 8을 만듬
	map = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));

	for (int i = 0; i < k; i++) {
		int in1, in2; cin >> in1 >> in2;
		map[in1][in2] = APPLE;
	}

	int l; cin >> l;
	for (int i = 0; i < l; i++) {
		int in1; char in2; cin >> in1 >> in2;
		snakeDir.push(make_pair(in1, in2));
	}

	printf("%d\n", move());
}