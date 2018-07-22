#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
//			 �� �� ��  �� �� ��
int dz[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 0, 1, 0, -1 };
int dx[] = { 0, 0, 1, 0, -1, 0 };

int n, m, h;
vector<vector<vector<int>>> map, visit;

// x,y,z�� ������ ����ü
typedef struct Point {
	int x, y, z;
	// ������
	Point() = default;
	Point(int z_, int y_, int x_) : z(z_), y(y_), x(x_) {}
};

int main(void) {
	cin >> m >> n >> h;
	
	// 3���� ���ͻ���
	visit = map = vector<vector<vector<int>>>(h, vector<vector<int>>(n, vector<int>(m, -1)));
	queue<Point> q;

	// create map
	// �ϳ��� ���������ִ� ��� true������ 
	bool zeroFlag = false;
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> map[k][i][j];
				// 0�� �ϳ��� ������ �÷��״� true
				if (map[k][i][j] == 0) zeroFlag = true;
				if (map[k][i][j] == 1) { 
					q.push(Point(k, i, j)); 
					visit[k][i][j] = 0; 
				}
			}
	//  ����ɶ����� ��� �;��ִ� ��� 0�� ����ϰ� ���� 
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

	// ��ã��
	int ans = 0;
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				// visit�� map�Ѵ� üũ�������!!!!!
				// map�� ���� 0�̰� visit�� ����-1 �ΰ��� 
				// �丶�䰡 ���;��´� �湮�� ���� ���� ������ �丶�� ����
				// visit�� -1 ������ map�ǰ��� -1�ΰ�춫�� Ʋ����.
				if (visit[k][i][j] == -1 && map[k][i][j] == 0) { printf("-1\n"); return 0; }
				ans = max(ans, visit[k][i][j]);
			}
	printf("%d\n", ans);
}