#include <iostream>
#include <vector>
#define GAMSI -1
#define RECOVER 1
#define WALL 6
using namespace std;

typedef struct CCTV {
	int y, x, ccNum;
	CCTV() {}
	CCTV(int y_, int x_, int ccNum_) : y(y_), x(x_), ccNum(ccNum_) {}
};

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int n, m;
int ans = 987654321;
vector<vector<int>> map;
vector<CCTV> cctv;

void move(int y, int x, int ccnum, int i, int j, int sum) {
	int ny = y;
	int nx = x;
	int dir = j;
	// iter = i = gamsicnt = �ѹ��� ������ �� �ִ� �����Ǽ�
	for (int iter = 0; iter < i; iter++) {
		while (1) {
			ny = ny + dy[dir];
			nx = nx + dx[dir];

			// ���� �Ѿ�� ����
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
			// �������� ����
			if (map[ny][nx] == WALL) break;
			// �ٸ� cctv ������ �Ѿ
			if (map[ny][nx] >= 1 && map[ny][nx] <= 5) continue;

			map[ny][nx] += sum;
		}
		ny = y; nx = x;
		if (ccnum == 2) dir = ((dir + 2) % 4);
		else dir = ((dir + 1) % 4);
	}
}

void go(int idx) {
	// ������ cctv���� �̵��Ѱ��, �簢���� ã��
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == 0) cnt += 1;
		ans = (ans > cnt ? cnt : ans);
		return;
	}
	//  cctv�� ��� ȸ���� �� �ִ���, ���ù����� ����
	int rotateNum, gamsiCnt;
	int ccNum = cctv[idx].ccNum;
	// ó�� ���ù���
	int gamsiDir = 0;

	if (ccNum == 1) { rotateNum = 4; gamsiCnt = 1; }
	else if (ccNum == 2) { rotateNum = 2; gamsiCnt = 2; }
	else if (ccNum == 3) { rotateNum = 4; gamsiCnt = 2; }
	else if (ccNum == 4) { rotateNum = 4; gamsiCnt = 3; }
	else { rotateNum = 1; gamsiCnt = 4; }

	

	for (int j = 0; j < rotateNum; j++) {
		// ���� �Ѱ� üũ
		move(cctv[idx].y, cctv[idx].x, ccNum, gamsiCnt, gamsiDir, GAMSI);
		go(idx + 1);
		// ����
		move(cctv[idx].y, cctv[idx].x, ccNum, gamsiCnt, gamsiDir++, RECOVER);
	}
}

int main(void) {
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			// cctv�߰��ϸ� ��ǥ�� ��� cctv���� ����
			if (map[i][j] != 0 && map[i][j] != WALL) cctv.push_back(CCTV(i, j, map[i][j]));
		}

	go(0);
	printf("%d\n", ans);
}