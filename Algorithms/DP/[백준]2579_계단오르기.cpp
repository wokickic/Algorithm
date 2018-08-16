#include <iostream>
#include <vector>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int main(void) {
	int n; cin >> n;
	vector<int> v(n);
	vector<vector<int>> dp(n, vector<int>(2));
	for (int i = 0; i < n; i++) cin >> v[i];
	
	//    0이면 1번연속, 1이면 2번연속
	dp[0][0] = v[0];
	dp[1][0] = v[1];
	dp[1][1] = v[0] + v[1];

	for (int i = 2; i < n; i++) {
		// [i - 2]번째 계단에서 i번 계단으로 올때, i - 2의 상태는 중요하지 않음
		// i - 2까지 한번에 온경우와 2번밟고 온 경우 비교해서 더큰숫자를 저장
		dp[i][0] = max(dp[i - 2][0] + v[i], dp[i - 2][1] + v[i]);
		
		// [i - 1]번째 계단에서 i번째 계단에 오려면 i - 1계단까지 1번에 온경우 만 가능
		// i - 1까지 2번밝고 온경우 i계단 까지는 연속 3번이되기 때문
		dp[i][1] = v[i] + dp[i - 1][0];
	}

	printf("%d\n",  max(dp[n - 1][0], dp[n - 1][1]));
}