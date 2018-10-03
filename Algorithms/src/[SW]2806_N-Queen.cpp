#include <iostream>
using namespace std;

int n;
int ans;

void dfs(int y, int col, int right_dig, int left_dig) {
	for (int x = 0; x < n; x++) {
		// x축 검사
		if (col & (1 << x)) continue;
		
		// 우대각 검사
		if (right_dig & (1 << (x + y))) continue;
		
		// 좌대각 검사, -1해주는 이유 0번째부터 시작하기 위해서
		if (left_dig & (1 << (y - x + n - 1))) continue;
		
		// 한줄로 한거
		// if ( (col & (1<<x)) || (right_dig & (1<<( x + y))) ||
		// (left_dig & (1<< ( y - x + n -1 )))) continue;
		// y == n이면 가장 아래 까지 내려온거 ans++
		if (y == (n - 1)) { ans++; return; }



		dfs(y + 1, col | (1 << x), right_dig | (1 << x + y), 
			left_dig | (1 << (y - x + n - 1)));
	}
}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n; ans = 0;
		int col = 1 << n;
		int right_dig = (1 << ((2 * n) - 1));
		int left_dig = (1 << ((2 * n) - 1));

		dfs(0, col, right_dig, left_dig);
		printf("#%d %d\n", t, ans);
	}
}