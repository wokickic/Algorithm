#include <iostream>
#include <vector>
#define min(a, b) ((a) > (b) ? (b) : (a))
#define INF 987654321
#define RED 0
#define BLUE 1
#define NFIND false
#define FIND true
using namespace std;

//          �� �� �� ��
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

// �������� ����, �������� ����������� �Ķ������� ������ �Ķ��� ���� ������
// �ƴϸ� ������ ���� ����
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
// ball : ������, stop : �������� or ������ ������, dir : ��������
bool move(Point& ball, Point stop, int dir) {
	int y = ball.y;
	int x = ball.x;
	// #�� �ƴϰ� �ٸ����� �ƴϸ� ���� �ݺ�
	for (;;) {
		y = y + dy[dir];
		x = x + dx[dir];
		// ���� ������ �������ִ� ����,
		// y,x ��ǥ���� n,m���� �־ ������ �������� ���� ���ۿ� �������� �Ǵ�
		if (y == hole.y && x == hole.x) { ball.y = n; ball.x = m; return FIND; }

		// �ٸ� ���� ��ǥ�� ��ġ�ų� ���� �ε����� ���� ��ã�Ҵٰ� ����
		if ((y == stop.y && x == stop.x ) ||map[y][x] == '#')  return NFIND;

		// ���� �ΰ�쿡 �Ȱɸ��� �̵��� ���� ball�� ���Ž�����
		ball.y = y; ball.x = x;
	}
	return NFIND;
}
//         dir�� �������
int getDir(int dir, int i) {
	// dir�� 0(������), 2(����)�� �¿� Ž��
	if (dir == 0 || dir == 2) {
		// ���������� �Ʒ���
		if (i == 0) return 1;
		// ����
		else return 3;
	}
	else {
	// dir�� 1(�Ʒ�), 3(��)�� ���� �Ʒ�, �� Ž��
		// ���� ������ ������
		if (i == 0) return 0;
		// ����
		else return 2;
	}
}

void dfs(Point red, Point blue, int dir, int cnt) {
	if (cnt > 10) return;
	// �ι��⸸ Ž��
	// ���� ������ -> �̸� ������ Ž���� ������
	// <-, -> ������ Ž���� �ʿ���� ��, �Ʒ��� Ž���غ����
	for (int i = 0; i < 2; i++) {
		Point nred = red;
		Point nblue = blue;
		bool r_flag, b_flag;
		
		// ����� ���� ������ ã�ƾߴ�
		int first = findBall(red, blue, dir);
		if (first == RED) {
			// �����Ÿ��� ������
			// nred�� �̵��ϰ� �̵��Ϸ�� ��ǥ�� �ٲ�
			r_flag = move(nred, blue, dir);
			// �Ķ��� ������ red�� �ƴ� �̵��� �Ϸ�� nred�� ������ ��������Ѵ�.
			b_flag = move(nblue, nred, dir);
		}
		else {
			// �Ķ��Ÿ��� ������
			b_flag = move(nblue, red, dir);
			r_flag = move(nred, nblue, dir);
		}
		// ���� 2���� ������� -> ����
		if (r_flag == FIND && b_flag == FIND) return;
		// �Ķ����� ������� -> ����
		else if (r_flag == NFIND && b_flag == FIND) return;
		// �������� ������� -> ����
		else if (r_flag == FIND && b_flag == NFIND) { ans = min(ans, cnt); return; }

		// ���� ��� �ƹ��͵� �Ȱɸ��� ���� �������� ��￩��
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
	// �ʹݿ� 4���� Ž��
	for (int i = 0; i < 4; i++)
		dfs(red, blue, i, 1);
	
	printf("%d\n", (ans == INF ? -1 : ans));
}