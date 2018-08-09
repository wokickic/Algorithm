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
// ���� �������� �����ϴ� ť
queue<pair<int, char>> snakeDir;

int n;

int getDir(int dir, char roDir) {
	if (roDir == 'L') dir = (dir - 1 < 0 ? 3 : dir - 1);
	else dir = (dir + 1 > 3 ? 0 : dir + 1);
	return dir;
}

int move() {
	// ���� deque��� �ڷᱸ���� ����ؼ� ��������
	// deque�� ���Ϳ� ť�� ���ĳ��� �Ͱ� ����� �ڷᱸ��
	// front�� back ���ʿ��� push�� pop�� ������
	deque<pair<int, int>> snake;
	// front�� ���� �Ӹ�, back�� ���� ������� �ϰ���
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

		// �̵��� ��ǥ�� ���� ������ return
		if (y == 0 || y  == (n + 1) || x == 0 || x == (n + 1)) return time;

		// �̵��� ��ǥ�� ���������� return
		if (map[y][x] == SNAKE) return time;

		// �̵��� ��ǥ�� ����� �ִ°��
		if (map[y][x] == APPLE) {
			// �ش���ǥ�� ������ �ٲ��ְ�
			map[y][x] = SNAKE;
			// ��ǥ�� front���༭ ���� ���̰� �þ
			snake.push_front(make_pair(y, x));
		}
		else {
			// ��� ������ �̵���ǥ�� ������ �ٲٰ� 
			map[y][x] = SNAKE;
			// front�� �Ӹ� ��ǥ �̵�
			snake.push_front(make_pair(y, x));
			// map���� ������ �ִ� �κ��� ��ĭ���� �ٲ���
			map[snake.back().first][snake.back().second] = 0;
			// �����κ��� pop���༭ ���� ���̴� ������ü �̵�
			snake.pop_back();
		}
		
		// �̵����� üũ
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
	
	// map�� ���鶧 1,1���� �����ϱ����ؼ� n�� 6�̸� 8 x 8�� ����
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