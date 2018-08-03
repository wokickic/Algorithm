#include <iostream>
#include <vector>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int n, m;
int ans;

vector<vector<char>> map;
vector<bool> check;

void dfs(int y, int x, int cnt) {
	int here = map[y][x];
	check[here - 65] = true;
	// �ִ�ĭ�� ���� 
	ans = MAX(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
			int next = map[ny][nx];
			// ���� ���ĺ� �湮 �������� ����
			if(!check[next - 65]){
				dfs(ny, nx, cnt + 1);
				// dfs()�ٳ�ͼ� �湮 Ǯ����
				check[next - 65] = false;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	map = vector<vector<char>>(n, vector<char>(m));
	check = vector<bool>(26, false); // ���ĺ� ������ŭ ���� �ʱ�ȭ

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	 //�빮�� A�� ��Ű��Ű�ڵ� 65
	dfs(0, 0, 1);
	printf("%d\n", ans);
}