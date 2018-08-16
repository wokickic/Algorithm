#include <iostream>
#include <vector>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int main(void) {
	int n; cin >> n;
	vector<int> v(n);
	vector<vector<int>> dp(n, vector<int>(2));
	for (int i = 0; i < n; i++) cin >> v[i];
	
	//    0�̸� 1������, 1�̸� 2������
	dp[0][0] = v[0];
	dp[1][0] = v[1];
	dp[1][1] = v[0] + v[1];

	for (int i = 2; i < n; i++) {
		// [i - 2]��° ��ܿ��� i�� ������� �ö�, i - 2�� ���´� �߿����� ����
		// i - 2���� �ѹ��� �°��� 2����� �� ��� ���ؼ� ��ū���ڸ� ����
		dp[i][0] = max(dp[i - 2][0] + v[i], dp[i - 2][1] + v[i]);
		
		// [i - 1]��° ��ܿ��� i��° ��ܿ� ������ i - 1��ܱ��� 1���� �°�� �� ����
		// i - 1���� 2����� �°�� i��� ������ ���� 3���̵Ǳ� ����
		dp[i][1] = v[i] + dp[i - 1][0];
	}

	printf("%d\n",  max(dp[n - 1][0], dp[n - 1][1]));
}