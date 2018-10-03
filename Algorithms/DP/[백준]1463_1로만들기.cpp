#include <iostream>
#include <vector>
#define min(a, b) ((a > b) ? (b) : (a))
using namespace std;

vector<int> memo;

int solve(int n) {
	if (n == 1) return 0;
	if (memo[n] > 0) return memo[n];

	// 1�� ���鼭 n���� 1���� ����Ƚ�� ����
	memo[n] = solve(n - 1) + 1;
	
	// 1�� ���Ŷ� ���ؼ� ������ ����Ƚ�� ���� memo[n]�� ���� 
	if (n % 3 == 0) memo[n] = min(memo[n], solve(n / 3) + 1);
	if( n % 2 == 0) memo[n] = min(memo[n], solve(n / 2) + 1);

	return memo[n];
}

int main(void) {
	int n; cin >> n;
	memo = vector<int>(n + 1, 0);

	printf("%d\n", solve(n));
}