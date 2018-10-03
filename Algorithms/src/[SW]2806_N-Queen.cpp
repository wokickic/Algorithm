#include <iostream>
using namespace std;

int n;
int ans;

void dfs(int y, int col, int right_dig, int left_dig) {
	for (int x = 0; x < n; x++) {
		// x�� �˻�
		if (col & (1 << x)) continue;
		
		// ��밢 �˻�
		if (right_dig & (1 << (x + y))) continue;
		
		// �´밢 �˻�, -1���ִ� ���� 0��°���� �����ϱ� ���ؼ�
		if (left_dig & (1 << (y - x + n - 1))) continue;
		
		// ���ٷ� �Ѱ�
		// if ( (col & (1<<x)) || (right_dig & (1<<( x + y))) ||
		// (left_dig & (1<< ( y - x + n -1 )))) continue;
		// y == n�̸� ���� �Ʒ� ���� �����°� ans++
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