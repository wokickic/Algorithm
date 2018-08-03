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
	// 최대칸수 저장 
	ans = MAX(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
			int next = map[ny][nx];
			// 다음 알파벳 방문 안했으면 ㄱㄱ
			if(!check[next - 65]){
				dfs(ny, nx, cnt + 1);
				// dfs()다녀와서 방문 풀어줌
				check[next - 65] = false;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	map = vector<vector<char>>(n, vector<char>(m));
	check = vector<bool>(26, false); // 알파벳 개수만큼 벡터 초기화

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	 //대문자 A의 아키스키코드 65
	dfs(0, 0, 1);
	printf("%d\n", ans);
}