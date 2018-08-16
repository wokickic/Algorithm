#include <iostream>
#include <vector>
#define MAX 987654321
#define WIRE -1
#define CORE 1

using namespace std;

typedef struct Core {
	int y, x;
	// ���� �پ������� true,
	// ���� ������������ false
	bool wall;
	Core() {}
	Core(int y_, int x_, bool wall_) : y(y_), x(x_), wall(wall_) {}
};

vector<vector<int>> map;
vector<Core> core;
int n, ansConnect, ansWire;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool move(int y, int x ,int dir, int sum, int& ncnt, int remove) {
	int cnt = 0;
	while(1) {
		y = y + dy[dir];
		x = x + dx[dir];
		
		// ��... ����... ������ �� ��������....
		// ������ �Ѿ�� �����ڸ����� ���Ἲ��, �ݺ��� �����ϰ� true ����
		if (y < 0 || x < 0 || y > n - 1 || x > n - 1) break;

		// �������
		if (sum == -1) 
			//���� ��ǥ�� �ھ �ְų� ������ ������ ���� ����
			if (map[y][x] == CORE || map[y][x] == WIRE) return false;
		
		// ��������
		if (sum == 1)
			// cnt�� remove�� ������ �̵��� ��ŭ �������� �Ϸ�
			if (cnt == remove) return false;

		// suum�� -1 �̸� ���� ��°�, 1�̸� �������·� ����
		map[y][x] += sum; ncnt = cnt = (cnt + 1);
	}
	return true;
}

void dfs(int idx, int connect, int cnt) {
	// idx�� �ھ��� ��ȣ
	if (idx == core.size()) {
		// ������ ���� ���ϱ�
		if (connect >= ansConnect) {
			if (connect == ansConnect) ansWire = (cnt < ansWire ? cnt : ansWire);
			else { ansConnect = connect; ansWire = cnt; }
		}
		return;
	}

	// ���� �پ������� 4���� �˻���ϰ� ���� �ھ�� �̵�
	if (core[idx].wall) dfs(idx + 1, connect + 1, cnt);

	// 4���� Ž���ϸ鼭 ���� �ߡ� �ѱ��
	else {
		int check = 0;// 4���� Ž��
		for (int j = 0; j < 4; j++) {
			int ncnt = 0;
			// �������� �����ϸ� ���� core�� �̵�
			if (move(core[idx].y, core[idx].x, j, -1, ncnt, 0))
				// ncnt + cnt = �̵��� ������ ���� + �̵��� ������ ����
				dfs(idx + 1, connect + 1, ncnt + cnt);
			
			// �������� �����ϸ� check 1������
			else check += 1;

			//���� ����
			// ncnt�� �̵��� ������ ����, ncnt��ŭ -1�� 0���� �ٲ���
			move(core[idx].y, core[idx].x, j, 1, ncnt, ncnt);
		}

		// check == 4 �� 4���� ��� ��������, ���� �ھ�� �Ѿ
		if (check == 4) dfs(idx + 1, connect, cnt);
	}
}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n; core.clear();
		map = vector<vector<int>>(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == CORE) {
					// ���� �پ������� wall�� ���� true�� ����
					if (i == 0 || j == 0 || i == n - 1 || j == n - 1) core.push_back(Core(i, j, true));
					else core.push_back(Core(i, j, false));
				}
			}
		ansWire =  MAX;
		ansConnect = 0;

		dfs(0, 0, 0);
		printf("#%d %d\n", t, ansWire);
	}
}