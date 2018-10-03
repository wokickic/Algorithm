#include <iostream>
#include <vector>
using namespace std;
const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, -1, 0, 0 };
int dic[7];

int n, m, y, x, k;
vector<vector<int>> map;

typedef struct DICE {
	int bottom, top;
	int right, left;
	int front, back;

	DICE(int b, int t, int r, int l, int f, int ba) :
		bottom(b), top(t), right(r), left(l), front(f), back(ba) {}

	void move(int dir) {
		int tmp = bottom;
		if (dir == 1) {
			bottom = right;
			right = top;
			top = left;
			left = tmp;
		}
		else if (dir == 2) {
			bottom = left;
			left = top;
			top = right;
			right = tmp;
		}
		else if (dir == 3) {
			bottom = back;
			back = top;
			top = front;
			front = tmp;
		}
		else {
			bottom = front;
			front = top;
			top = back;
			back = tmp;
		}
	}
};

int main(void) {
	cin >> n >> m >> y >> x >> k;
	map = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	DICE dice(6, 0, 3, 4, 5, 2);
	for (int i = 0; i < k; i++) {
		int dir; cin >> dir;
		int ny = y + dy[dir - 1];
		int nx = x + dx[dir - 1];

		// 범위 넘어가면 패쓰
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		y = ny; x = nx;
		dice.move(dir);

		if (map[y][x] == 0) map[y][x] = dic[dice.bottom];
		else { dic[dice.bottom] = map[y][x]; map[y][x] = 0; }
		printf("%d\n", dic[dice.top]);
	}
}