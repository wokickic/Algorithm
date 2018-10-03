#include <iostream>
#include <vector>
#define LINK 1
#define NLINK 0
#define MIN(a, b) ((a) > (b) ? (b) : (a))
using namespace std;

// 세로선, 가로선의 개수, 가로선을 놓을수 있는 위치의 개수
int n, m, h;
int ans = 987654321;
vector<vector<int>> ladder;

bool find() {
	for (int i = 1; i <= n; i++) {
		int b = i;
		for (int a = 1; a < h + 1; a++) {
			if (ladder[a][b] == LINK) b += 1;
			else if (ladder[a][b - 1] == LINK) b -= 1;
		}
		if (i != b) { return false; }
	}
	return true;
}

// 가로선, 세로선, 연결갯수
void dfs(int a, int b, int cnt) {
	if (find()) ans = MIN(ans, cnt); 
	if (cnt == 3 || ans == 0) return;
	
	// 가로
	for (int i = a; i <= h;i++) {
		// 세로
		for (int j = (i == a ? b : 1); j < n;) {
			// 사다리 연결하는 경우
			if (ladder[i][j] == NLINK && ladder[i][j + 1] == NLINK) {
				ladder[i][j] = LINK;
				dfs(i, j + 2, cnt + 1);
				ladder[i][j] = NLINK;
				j += 1;
			}
			// 사다리 연결 못하는경우
			else j += 2;
		}
	}
}

int main(void) {
	cin >> n >> m >> h;
	ladder = vector<vector<int>>(h + 1, vector<int>(n + 2, 0));

	for (int i = 0; i < m; i++) {
		// b번 세로선과 b + 1세로선을 a번 가로선에 연결
		int a, b; cin >> a >> b; 
		ladder[a][b] = LINK;
	}
	
	dfs(1, 1, 0);
	printf("%d\n", (ans <= 3 ? ans : -1));
}