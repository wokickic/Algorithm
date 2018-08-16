#include <iostream>
#include <vector>
#define CLEAN 2
#define WALL 1
#define NCLEAN 0
using namespace std;

//          �� �� �� ��
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int m, n;
vector<vector<int>> map;

int move(int r, int c, int dir) {
	int cnt = 0;
	int y = r;
	int x = c;
	int d = dir;

	// ó����ġ û��, û��ĭ�� ���� 1����
	map[y][x] = CLEAN; cnt++;

	while (1) {
		// dircheck : 4����Ȯ���ؼ�, ����ĭ���� �̵�����, �������� �����ϴ� ����
		// nd : ���� ��������, d�� ���ϰ� nd���ϴ� ������ �����Ҷ� ������� �������� �ؾ��ϱ⶧����
		int dircheck = 0; int nd = d;
		for (int i = 0; i < 4; i++) {
			// �������� �̵�
			nd = (nd + 3) % 4;
			int ny = y + dy[nd];
			int nx = x + dx[nd];
			// ���� ��ǥ�� û�Ҿ������� y, x, d�� �̵��� ������ �ٲ��ְ� �ݺ��� ����
			if (map[ny][nx] == NCLEAN) {
				y = ny; x = nx; d = nd;
				break;
			}
			// �̵��� ��ǥ�� �̹�û�� �Ϸ� �ų� ���̶� û�Ҹ��Ѱ��
			// 1���� �����ش�
			dircheck++;
		}

		// dircheck != 4�̸� û�� ���� ������ ã�����̱� ������ 
		// (y,x)û�Ҹ�ŷ�ϰ� ���� �ݺ�����
		if (dircheck != 4) { map[y][x] = CLEAN; cnt++; }
		
		//
		else {
			// back�� ���� ������ �ٶ󺸰� �����ϴ� ��ǥ
			int back = (d + 2) % 4;
			int ny = y + dy[back];
			int nx = x + dx[back];

			// ���������� ���̸� ���̻� �̵��� �Ұ����ϱ⶧���� cnt �������ְ� �Լ�����
			if (map[ny][nx] == WALL) return cnt;
			// �׷��� ������ (y,x)�� ������ ��ǥ�� ������Ʈ ���ְ�, ������ ������� ����
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