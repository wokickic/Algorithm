#include <iostream>
#include <vector>
#define min(a, b) ((a > b) ? (b) : (a))
using namespace std;

vector<int> memo;

int solve(int n) {
	if (n == 1) return 0;
	if (memo[n] > 0) return memo[n];

	// 1씩 빼면서 n에서 1까지 연산횟수 저장
	memo[n] = solve(n - 1) + 1;
	
	// 1씩 뺀거랑 비교해서 더작은 연산횟수 값을 memo[n]에 저장 
	if (n % 3 == 0) memo[n] = min(memo[n], solve(n / 3) + 1);
	if( n % 2 == 0) memo[n] = min(memo[n], solve(n / 2) + 1);

	return memo[n];
}

int main(void) {
	int n; cin >> n;
	memo = vector<int>(n + 1, 0);

	printf("%d\n", solve(n));
}